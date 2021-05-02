#include "ComponentSprite.hpp"

ComponentSprite::ComponentSprite(Object* owner) : Component(owner) {
}

void ComponentSprite::Load(const std::string& filePath)
{
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
}

void ComponentSprite::Draw(Window& window)
{
    window.Draw(sprite);
}

void ComponentSprite::LateUpdate(float deltaTimeFps) {
    sprite.setPosition(owner->transform->GetPosition());
}