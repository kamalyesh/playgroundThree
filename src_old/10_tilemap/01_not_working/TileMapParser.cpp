#include "TileMapParser.hpp"
#include <string.h>
TileMapParser::TileMapParser(ResourceAllocator<sf::Texture> &textureAllocator)
    : textureAllocator(textureAllocator) {}

std::vector<std::shared_ptr<Object>> TileMapParser::Parse(const std::string &file, sf::Vector2i offset)
{
  char *fileLoc = new char[file.size() + 1]; // 1

  //TODO: make multi format version of string copy
#ifdef MACOS
  strlcpy(fileLoc, file.c_str(), file.size() + 1);
#else

  strncpy(fileLoc, file.c_str(), file.size() + 1);
#endif

  //TODO: error checking - check file exists before attempting open.
  rapidxml::file<> xmlFile(fileLoc);
  rapidxml::xml_document<> doc;
  doc.parse<0>(xmlFile.data());
  xml_node<> *rootNode = doc.first_node("map");

  // Loads tile layers from XML.
  std::shared_ptr<MapTiles> tiles = BuildMapTiles(rootNode);

  // We need these to calculate the tiles position in world space
  int tileSizeX = std::atoi(rootNode->first_attribute("tilewidth")->value());
  int tileSizeY = std::atoi(rootNode->first_attribute("tileheight")->value());
  int mapsizeX = std::atoi(rootNode->first_attribute("width")->value());
  int mapsizeY = std::atoi(rootNode->first_attribute("height")->value());

  // This will contain all of our tiles as objects.
  std::vector<std::shared_ptr<Object>> tileObjects;

  // 2
  // We iterate through each layer in the tile map
  for (const auto &layer : *tiles)
  {
    // And each tile in the layer
    for (const auto &tile : *layer.second)
    {
      std::shared_ptr<TileInfo> tileInfo = tile->properties;

      std::shared_ptr<Object> tileObject = std::make_shared<Object>();

      //TODO: tile scale should be set at the data level.
      const unsigned int tileScale = 3;

      // Allocate sprite.
      auto sprite = tileObject->AddComponent<ComponentSprite>();
      sprite->SetTextureAllocator(&textureAllocator);
      sprite->Load(tileInfo->textureID);
      sprite->SetTextureRect(tileInfo->textureRect);
      sprite->SetScale((float)tileScale, (float)tileScale);
      // Calculate world position.
      float x = tile->x * tileSizeX * tileScale + offset.x;
      float y = tile->y * tileSizeY * tileScale + offset.y;
      tileObject->transform->SetPosition(x, y);

      // Add new tile Object to the collection.
      tileObjects.emplace_back(tileObject);
    }
  }

  return tileObjects;
}

std::shared_ptr<MapTiles> TileMapParser::BuildMapTiles(xml_node<> *rootNode)
{
  std::shared_ptr<TileSheetData> tileSheetData = BuildTileSheetData(rootNode);

  std::shared_ptr<MapTiles> map = std::make_shared<MapTiles>();

  // We loop through each layer in the XML document.
  for (xml_node<> *node = rootNode->first_node("layer"); node; node = node->next_sibling())
  {
    std::pair<std::string, std::shared_ptr<Layer>> mapLayer = BuildLayer(node, tileSheetData);

    map->emplace(mapLayer);
  }

  return map;
}

std::shared_ptr<TileSheetData> TileMapParser::BuildTileSheetData(xml_node<> *rootNode)
{
  TileSheetData tileSheetData;

  // Traverse to the tile set node.
  xml_node<> *tilesheetNode = rootNode->first_node("tileset");

  //TODO: add error checking to ensure these values actually exist.
  //TODO: add support for multiple tile sets.
  //TODO: implement this.
  int firstid = std::atoi(tilesheetNode->first_attribute("firstgid")->value());

  // Build the tile set data.
  tileSheetData.tileSize.x = std::atoi(tilesheetNode->first_attribute("tilewidth")->value());
  tileSheetData.tileSize.y = std::atoi(tilesheetNode->first_attribute("tileheight")->value());
  int tileCount = std::atoi(tilesheetNode->first_attribute("tilecount")->value());
  tileSheetData.columns = std::atoi(tilesheetNode->first_attribute("columns")->value());
  tileSheetData.rows = tileCount / tileSheetData.columns;

  xml_node<> *imageNode = tilesheetNode->first_node("image");
  tileSheetData.textureId = textureAllocator.Add(std::string(imageNode->first_attribute("source")->value()));

  //TODO: add error checking - we want to output a
  //message if the texture is not found.

  tileSheetData.imageSize.x = std::atoi(imageNode->first_attribute("width")->value());
  tileSheetData.imageSize.y = std::atoi(imageNode->first_attribute("height")->value());

  return std::make_shared<TileSheetData>(tileSheetData);
}

std::pair<std::string, std::shared_ptr<Layer>> TileMapParser::BuildLayer(xml_node<>* layerNode, std::shared_ptr<TileSheetData> tileSheetData)
{
    
    TileSet tileSet;
    std::shared_ptr<Layer> layer = std::make_shared<Layer>();
    
    int width = std::atoi(layerNode->first_attribute("width")->value());
    int height = std::atoi(layerNode->first_attribute("height")->value());
    
    xml_node<>* dataNode = layerNode->first_node("data");
    char* mapIndices = dataNode->value();
    
    std::stringstream fileStream(mapIndices);
    
    int count = 0;
    
    std::string line;
    while (fileStream.good())
    {
        std::string substr;
        std::getline(fileStream, substr, ',');
        
        if (!Utilities::IsInteger(substr))
        {
            substr.erase(std::remove(substr.begin(), substr.end(), '\r'), substr.end());
            substr.erase(std::remove(substr.begin(), substr.end(), '\n'), substr.end());
            
            //TODO: add additional check to confirm that the character removals have worked:
            /*
            if(!Utilities::IsInteger(substr))
            {
                //String is still not integer.
            }
            */
        }
        
        int tileId = std::stoi(substr);
        
        if (tileId != 0)
        {
            auto itr = tileSet.find(tileId);
            if (itr == tileSet.end())
            {
                int textureX = tileId % tileSheetData->columns - 1;
                int textureY = tileId / tileSheetData->columns;
                
                std::shared_ptr<TileInfo> tileInfo = std::make_shared<TileInfo>(tileSheetData->textureId, tileId, sf::IntRect(textureX * tileSheetData->tileSize.x, textureY * tileSheetData->tileSize.y, tileSheetData->tileSize.x, tileSheetData->tileSize.y));
                
                itr = tileSet.insert(std::make_pair(tileId, tileInfo)).first;
            }
            
            std::shared_ptr<Tile> tile = std::make_shared<Tile>();
            
            // Bind properties of a tile from a set.
            tile->properties = itr->second;
            tile->x = count % width - 1;
            tile->y = count / width;
            

            layer->emplace_back(tile);
        }
        
        count++;
    }
    
    const std::string layerName = layerNode->first_attribute("name")->value();
    return std::make_pair(layerName, layer);
}
