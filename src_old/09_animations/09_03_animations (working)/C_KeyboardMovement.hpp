#ifndef ComponentKeyboardMovement_hpp
#define ComponentKeyboardMovement_hpp

#include "Component.hpp"
#include "C_Animation.hpp"
#include "Input.hpp"
#include "Object.hpp"

class ComponentKeyboardMovement : public Component
{
public:
    ComponentKeyboardMovement(Object *owner);

    void SetInput(Input *input);
    void SetMovementSpeed(int moveSpeed);
    void Awake() override;
    void Update(float deltaTime) override;

private:
    int moveSpeed;
    Input *input;
    std::shared_ptr<ComponentAnimation> animation;
};

#endif /* ComponentKeyboardMovement_hpp */
