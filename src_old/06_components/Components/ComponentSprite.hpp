#ifndef Componentte_hpp
#define Componentte_hpp

#include "Component.hpp"
#include "Object.hpp"

class ComponentSprite : public Component
{
public:
    ComponentSprite(Object* owner);
    
	// Loads a sprite from file.
    void Load(const std::string& filePath);  
    
	// We override the draw method so we can draw our sprite.
    void Draw(Window& window) override; 

    void LateUpdate(float deltaTimeFps) override;

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif /* Componentte_hpp */