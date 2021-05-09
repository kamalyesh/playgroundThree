#include "ComponentTransform.hpp"

ComponentTransform::ComponentTransform(Object *owner)
    : Component(owner), position(0.f, 0.f) {}

void ComponentTransform::SetPosition(const sf::Vector2f pos)
{
    position = pos;
}

void ComponentTransform::SetPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}

void ComponentTransform::AddPosition(sf::Vector2f pos)
{
    position += pos;
}

void ComponentTransform::AddPosition(float x, float y)
{
    position.x += x;
    position.y += y;
}

void ComponentTransform::SetX(float x)
{
    position.x = x;
}

void ComponentTransform::SetY(float y)
{
    position.y = y;
}

void ComponentTransform::AddX(float x)
{
    position.x += x;
}

void ComponentTransform::AddY(float y)
{
    position.y += y;
}

const sf::Vector2f &ComponentTransform::GetPosition() const
{
    return position;
}