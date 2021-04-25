#include "Game.hpp"

Game::Game() : window("pg3")
{
    this->CalculateDeltaTimeFps();

    std::cout << workingDir.Get() << std::endl;
    std::cout << workingDir.testExists(workingDir.Resources() + "texture/viking.png") << std::endl;

    texture.loadFromFile(workingDir.Resources() + "texture/viking.png");
    sprite.setTexture(texture);
}

void Game::Update()
{
    window.Update();

    const sf::Vector2f &spritePos = sprite.getPosition();
    const int pixelsToMovePerSec_normal = 100;
    const int pixelsToMovePerSec_fast = 150;

    int movement = pixelsToMovePerSec_normal;
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

    const float xFrameMovement = xMovement * deltaTimeFps;
    const float yFrameMovement = yMovement * deltaTimeFps;
    sprite.setPosition(spritePos.x + xFrameMovement, spritePos.y + yFrameMovement);
}

void Game::LateUpdate() {}

void Game::Draw()
{
    window.BeginDraw();
    window.Draw(sprite);
    window.EndDraw();
}

bool Game::IsRunning() const
{
    // We’ll return true here for now but this will be
    // changed shortly as we need a method of closing the window.
    return window.IsOpen();
}

void Game::CalculateDeltaTimeFps()
{
    deltaTimeFps = gameClock.restart().asSeconds();
}

void Game::CaptureInput()
{
    input.Update();
}