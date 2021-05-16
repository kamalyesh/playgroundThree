#ifndef ComponentTransform_hpp
#define ComponentTransform_hpp

#include "Component.hpp"

class ComponentTransform : public Component
{
public:
    ComponentTransform(Object *owner);

    void SetPosition(float x, float y);
    void SetPosition(const sf::Vector2f pos);

    void AddPosition(float x, float y);
    void AddPosition(sf::Vector2f pos);

    void SetX(float x);
    void SetY(float y);

    void AddX(float x);
    void AddY(float y);

    const sf::Vector2f &GetPosition() const;

private:
    sf::Vector2f position;
};

#endif /* ComponentTransform_hpp */
