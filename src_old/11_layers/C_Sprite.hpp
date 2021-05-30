#ifndef ComponentSprite_hpp
#define ComponentSprite_hpp

#include "Component.hpp"
#include "C_Drawable.hpp"
#include "C_Transform.hpp"
#include "Object.hpp"
#include "ResourceAllocator.hpp"

class ComponentSprite : public Component, public ComponentDrawable
{
public:
    ComponentSprite(Object* owner);
    
    void SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator);
    
    void Load(int id);
    void Load(const std::string& filePath);
    
    void LateUpdate(float deltaTime) override;
    void Draw(Window& window) override;

    void SetTextureRect(int x, int y, int width, int height);
    void SetTextureRect(const sf::IntRect& rect);
    void SetScale(float scaleX, float scaleY);
    
private:
    ResourceAllocator<sf::Texture>* allocator;
    sf::Sprite sprite;
    int currentTextureID;
};

#endif /* ComponentSprite_hpp */
