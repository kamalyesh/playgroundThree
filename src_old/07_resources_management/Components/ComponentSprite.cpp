#include "ComponentSprite.hpp"

ComponentSprite::ComponentSprite(Object *owner) : Component(owner)
{
}

void ComponentSprite::SetTextureAllocator(ResourceAllocator<sf::Texture> *allocator)
{
    this->allocator = allocator;
}

void ComponentSprite::Load(int id)
{
    if (id >= 0)
    {
        std::shared_ptr<sf::Texture> texture = allocator->Get(id);
        sprite.setTexture(*texture);
    }
}

void ComponentSprite::Load(const std::string &filePath)
{
    if (allocator)
    {
        int textureID = allocator->Add(filePath);

        if (textureID >= 0)
        {
            std::shared_ptr<sf::Texture> texture = allocator->Get(textureID);
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