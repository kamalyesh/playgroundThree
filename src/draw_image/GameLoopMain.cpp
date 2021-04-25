#include "GameLoopMain.hpp"

int GameLoopMain::main()
{
    Game game;

    // Start the game loop
    while (game.IsRunning())
    {
        game.Update();
        game.LateUpdate();
        game.Draw();
    }
}