#ifndef RESOURCE_PATH_HPP
#define RESOURCE_PATH_HPP

#include <string>
#include <sys/stat.h>
#include <stdlib.h>

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
    inline const std::string& Current()
    {
        return path;
    }
    inline const std::string& Resources()
    {
        return resources;
    }
    inline const std::string& Textures(std::string name)
    {
        return textures + name;
    }    
    inline const bool testExists(const std::string& name) {
        struct stat buffer;   
        return (stat (name.c_str(), &buffer) == 0); 
    }

private:
    std::string path;
    std::string resources;
    std::string textures;
};



#endif

