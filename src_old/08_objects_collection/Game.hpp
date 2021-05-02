#ifndef Game_hpp
#define Game_hpp

#include <iostream>

#include "./Input.hpp"
#include "./ResourceAllocator.hpp"
#include "./Window.hpp"
#include "./WorkingDirectory.hpp"
#include "./SceneStateMachine.hpp"
#include "./Scenes/SceneSplashScreen.hpp"
#include "./Scenes/SceneGame.hpp"

using namespace std;
class Game
{
public:
    Game();
    void Update();
    void LateUpdate();
    void Draw();
    bool IsRunning() const;
    void CalculateDeltaTimeFps();
    void CaptureInput();

private:
    Window window;
    WorkingDirectory workingDir;
    sf::Clock gameClock;
    float deltaTimeFps;
    Input input;
    SceneStateMachine sceneStateMachine;
    ResourceAllocator<sf::Texture> textureAllocator;
};

#endif /* Game_hpp */