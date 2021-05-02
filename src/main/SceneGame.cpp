#include "SceneGame.hpp"
#include <iostream>
#define P(s) std::cout << s << std::endl;

SceneGame::SceneGame(WorkingDirectory &workingDirectory) : workingDir(workingDirectory)
{
    // P("SceneGame::SceneGame")
}

void SceneGame::OnCreate()
{
    // P(workingDir.Resources() + "texture/viking.png")
    vikingTexture.loadFromFile(workingDir.Resources() + "texture/viking.png");
    vikingSprite.setTexture(vikingTexture);
}

void SceneGame::OnDestroy()
{
    // P("SceneGame::OnDestroy")
}

void SceneGame::ProcessInput()
{
    // P("SceneGame::ProcessInput")
    input.Update();
}

void SceneGame::Update(float deltaTimeFps)
{
    // P("SceneGame::Update")
    const sf::Vector2f &spritePos = vikingSprite.getPosition();
    const int pixelsToMovePerSec_normal = 100;
    const int pixelsToMovePerSec_fast = 150;

    int movement = pixelsToMovePerSec_normal;
    // P("SceneGame::Update movement "<< movement)
    int xMovement = 0;
    if (input.IsKeyPressed(Input::Key::Left))
    {
        xMovement = -movement;
    }
    else if (input.IsKeyPressed(Input::Key::Right))
    {
        xMovement = movement;
    }
    int yMovement = 0;
    if (input.IsKeyPressed(Input::Key::Up))
    {
        yMovement = -movement;
    }
    else if (input.IsKeyPressed(Input::Key::Down))
    {
        yMovement = movement;
    }
    // P("SceneGame::Update movement (" << xMovement << "," << yMovement << ")")
    const float xFrameMovement = xMovement * deltaTimeFps;
    const float yFrameMovement = yMovement * deltaTimeFps;
    // P("SceneGame::Update FrameMovement (" << xFrameMovement << "," << yFrameMovement << ")")
    // P("SceneGame::Update viking pos (" << (spritePos.x + xFrameMovement) << "," << (spritePos.y + yFrameMovement) << ")")
    vikingSprite.setPosition(spritePos.x + xFrameMovement, spritePos.y + yFrameMovement);
}

void SceneGame::Draw(Window &window)
{
    // P("SceneGame::Draw")
    window.Draw(vikingSprite);
}
