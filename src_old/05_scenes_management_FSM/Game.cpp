#include "Game.hpp"

Game::Game() : window("pg3")
{
    std::shared_ptr<SceneSplashScreen> splashScreen = std::make_shared<SceneSplashScreen>(workingDir, sceneStateMachine, window);
    std::shared_ptr<SceneGame> gameScene1 = std::make_shared<SceneGame>(workingDir);
    // std::shared_ptr<SceneGame> gameScene2 = std::make_shared<SceneGame>(workingDir);

    unsigned int splashScreenID = sceneStateMachine.Add(splashScreen);
    unsigned int gameSceneID1 = sceneStateMachine.Add(gameScene1);
    // unsigned int gameSceneID2 = sceneStateMachine.Add(gameScene2);

    splashScreen->setSwitchToScene(gameSceneID1);
    sceneStateMachine.SwitchTo(splashScreenID);

    this->CalculateDeltaTimeFps();
}

void Game::Update()
{
    window.Update();
    sceneStateMachine.Update(deltaTimeFps);
}

void Game::LateUpdate()
{
    sceneStateMachine.LateUpdate(deltaTimeFps);
}

void Game::Draw()
{
    window.BeginDraw();
    // window.Draw(sprite);
    sceneStateMachine.Draw(window);
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
    sceneStateMachine.ProcessInput();
}