#include "GameLoopMain.hpp"

int GameLoopMain::main()
{
    Game game;

    // Start the game loop
    while (game.IsRunning())
    {
        game.CaptureInput();
        game.Update();
        game.LateUpdate();
        game.Draw();
        game.CalculateDeltaTime();
    }
}