#include "ComponentKeyboardMovement.hpp"
#include "Object.hpp"

ComponentKeyboardMovement::ComponentKeyboardMovement(Object *owner)
	: Component(owner), moveSpeed(100) {}

void ComponentKeyboardMovement::SetInput(Input *input)
{
	this->input = input;
}

void ComponentKeyboardMovement::SetMovementSpeed(int moveSpeed)
{
	this->moveSpeed = moveSpeed;
}

void ComponentKeyboardMovement::Update(float deltaTimeFps)
{
	if (input == nullptr)
	{
		return;
	}

	int xMove = 0;
	if (input->IsKeyPressed(Input::Key::Left))
	{
		xMove = -moveSpeed;
	}
	else if (input->IsKeyPressed(Input::Key::Right))
	{
		xMove = moveSpeed;
	}

	int yMove = 0;
	if (input->IsKeyPressed(Input::Key::Up))
	{
		yMove = -moveSpeed;
	}
	else if (input->IsKeyPressed(Input::Key::Down))
	{
		yMove = moveSpeed;
	}

	float xFrameMove = xMove * deltaTimeFps;
	float yFrameMove = yMove * deltaTimeFps;

	owner->transform->AddPosition(xFrameMove, yFrameMove);
}