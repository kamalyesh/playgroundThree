#ifndef Componentte_hpp
#define Componentte_hpp

#include "Component.hpp"
#include "Object.hpp"
#include "../ResourceAllocator.hpp"

class ComponentSprite : public Component
{
public:
    ComponentSprite(Object *owner);

    // Loads a sprite from file.
    void Load(const std::string &filePath);
    // We add a new overloaded Load method that accepts a texture id.
    void Load(int id);

    // We override the draw method so we can draw our sprite.
    void Draw(Window &window) override;

    void LateUpdate(float deltaTimeFps) override;

    void SetTextureAllocator(ResourceAllocator<sf::Texture> *allocator);

private:
    ResourceAllocator<sf::Texture> *allocator;
    sf::Sprite sprite;
};

#endif /* Componentte_hpp */