#ifndef ComponentKeyboardMovement_hpp
#define ComponentKeyboardMovement_hpp

#include "Component.hpp"
#include "../Input.hpp"

class ComponentKeyboardMovement : public Component
{
public:
    ComponentKeyboardMovement(Object * owner);
    
    void SetInput(Input* input);
    void SetMovementSpeed(int moveSpeed);
    
    void Update(float deltaTimeFps) override;
    
private:
    int moveSpeed; 
    Input* input;
};

#endif /* ComponentKeyboardMovement_hpp */