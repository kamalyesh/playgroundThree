#ifndef RESOURCE_PATH_HPP
#define RESOURCE_PATH_HPP

#include <string>

#ifdef MACOS
#include "CoreFoundation/CoreFoundation.h"
#endif

class WorkingDirectory
{
public:
    WorkingDirectory();
    
    inline const std::string& Get()
    {
        return path;
    }
    inline const std::string& Source()
    {
        return source;
    }
    inline const std::string& Resources()
    {
        return resources;
    }
    inline const std::string& Texture(/* std::string textureName */)
    {
        return texture ;//+ textureName;
    }
    inline const std::string& Tilemap(/* std::string tilemapName */)
    {
        return tilemap ;//+ tilemapName;
    }
private:
    std::string path;
    std::string source;
    std::string resources;
    std::string texture;
    std::string tilemap;
};

#endif
