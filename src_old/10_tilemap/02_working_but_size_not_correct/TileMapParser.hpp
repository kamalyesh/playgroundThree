#ifndef TileMapParser_hpp
#define TileMapParser_hpp

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <sstream>

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>

#include "Tile.h"
#include "Utilities.h"
#include "Object.hpp"
#include "C_Sprite.hpp"
#include "WorkingDirectory.hpp"

using namespace rapidxml;

struct TileSheetData
{
    // The texture id will be retrieved by using our texture allocator.
    int textureId;          // The id of the tile sets texture.
    sf::Vector2u imageSize; // The size of the texture.
    int columns;            // How many columns in the tile sheet.
    int rows;               // How many rows in the tile sheet.
    sf::Vector2u tileSize;  // The size of an individual tile.
};

using Layer = std::vector<std::shared_ptr<Tile>>;

// Stores layer names with layer.
using MapTiles = std::map<std::string, std::shared_ptr<Layer>>;

// Stores the different tile types that can be used.
using TileSet = std::unordered_map<unsigned int, std::shared_ptr<TileInfo>>;

class TileMapParser
{
public:
  TileMapParser(/* WorkingDirectory &workingDir, */ ResourceAllocator<sf::Texture> &textureAllocator);

  std::vector<std::shared_ptr<Object>>
  Parse(const std::string &file, sf::Vector2i offset);
    
private:
    std::shared_ptr<TileSheetData> BuildTileSheetData(xml_node<>* rootNode);
    std::shared_ptr<MapTiles> BuildMapTiles(xml_node<>* rootNode);
    std::pair<std::string, std::shared_ptr<Layer>> 
		BuildLayer(
			xml_node<>* layerNode, std::shared_ptr<TileSheetData> tileSheetData
		);
    
    ResourceAllocator<sf::Texture>& textureAllocator;
    // WorkingDirectory& workingDir;
};

#endif /* TileMapParser_hpp */