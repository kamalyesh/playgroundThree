#ifndef Componentte_hpp
#define Componentte_hpp

#include "Component.hpp"
#include "ComponentTransform.hpp"
#include "Object.hpp"
#include "ResourceAllocator.hpp"

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

    void SetTextureRect(int x, int y, int width, int height);
    void SetTextureRect(const sf::IntRect &rect);

private:
    ResourceAllocator<sf::Texture> *allocator;
    sf::Sprite sprite;

    // keep track of our currently set texture.
    int currentTextureID;
};

#endif /* Componentte_hpp */