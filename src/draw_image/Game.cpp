#include "Game.hpp"

Game::Game() : window("pg3")
{
    
    std::cout << workingDir.Get() << std::endl;
    std::cout << workingDir.testExists(workingDir.Resources() + "texture/viking.png") << std::endl;
    
    texture.loadFromFile(workingDir.Resources() + "texture/viking.png");
    sprite.setTexture(texture);
}

void Game::Update()
{
    window.Update();
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
