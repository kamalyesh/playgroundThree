#include "ComponentSprite.hpp"

ComponentSprite::ComponentSprite(Object *owner) : Component(owner), currentTextureID(-1)
{
}

void ComponentSprite::SetTextureAllocator(ResourceAllocator<sf::Texture> *allocator)
{
    this->allocator = allocator;
}

void ComponentSprite::Load(int id)
{
    if (id >= 0 && id != currentTextureID)
    {
        currentTextureID = id;
        std::shared_ptr<sf::Texture> texture = allocator->Get(currentTextureID);
        sprite.setTexture(*texture);
    }
}

void ComponentSprite::Load(const std::string &filePath)
{
    if (allocator)
    {
        int textureID = allocator->Add(filePath);

        if (textureID >= 0 && textureID != currentTextureID)
        {
            currentTextureID = textureID;
            std::shared_ptr<sf::Texture> texture = allocator->Get(currentTextureID);
            sprite.setTexture(*texture);
        }
    }
}

void ComponentSprite::Draw(Window &window)
{
    window.Draw(sprite);
}

void ComponentSprite::LateUpdate(float deltaTimeFps)
{
    sprite.setPosition(owner->transform->GetPosition());
}

void ComponentSprite::SetTextureRect(int x, int y, int width, int height)
{
    sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

void ComponentSprite::SetTextureRect(const sf::IntRect &rect)
{
    sprite.setTextureRect(rect);
}