#include "C_KeyboardMovement.hpp"
#include <iostream>
#define P(s) std::cout<<s<<std::endl;
ComponentKeyboardMovement::ComponentKeyboardMovement(Object *owner) : Component(owner), moveSpeed(100) {}

void ComponentKeyboardMovement::SetInput(Input *input)
{
    this->input = input;
}

void ComponentKeyboardMovement::SetMovementSpeed(int moveSpeed)
{
    this->moveSpeed = moveSpeed;
}

void ComponentKeyboardMovement::Update(float deltaTime)
{
    if (input == nullptr)
    {
        return;
    }

    int movementSpeed = 0;
    if (input->IsKeyPressed(Input::Key::Shift))
    {
        P("Fast")
        movementSpeed = moveSpeed * 3;
    }
    else
    {

        movementSpeed = moveSpeed;
    }

    int xMove = 0;
    if (input->IsKeyPressed(Input::Key::Left))
    {
        xMove = -movementSpeed;
        animation->SetAnimationDirection(FacingDirection::LEFT);
    }
    else if (input->IsKeyPressed(Input::Key::Right))
    {
        xMove = movementSpeed;
        animation->SetAnimationDirection(FacingDirection::RIGHT);
    }

    int yMove = 0;
    if (input->IsKeyPressed(Input::Key::Up))
    {
        yMove = -movementSpeed;
    }
    else if (input->IsKeyPressed(Input::Key::Down))
    {
        yMove = movementSpeed;
    }


    if(xMove == 0 && yMove == 0) {
        animation->SetAnimationState(AnimationState::IDLE);
    } else {
        animation->SetAnimationState(AnimationState::WALK);
    }

    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;

    owner->transform->AddPosition(xFrameMove, yFrameMove);
}

void ComponentKeyboardMovement::Awake()
{
    animation = owner->GetComponent<ComponentAnimation>();
}
