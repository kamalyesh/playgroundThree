#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "./Window.hpp"
#include "./WorkingDirectory.hpp"

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

private:
    Window window;
    WorkingDirectory workingDir;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock gameClock;
    float deltaTimeFps;
};

#endif /* Game_hpp */