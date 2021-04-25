#include "Game.hpp"

Game::Game() : window("pg3")
{
}

void Game::Update()
{
    window.Update();
}

void Game::LateUpdate() {}

void Game::Draw()
{
    window.BeginDraw();
    window.EndDraw();
}

bool Game::IsRunning() const
{
    // We’ll return true here for now but this will be
    // changed shortly as we need a method of closing the window.
    return window.IsOpen();
}
