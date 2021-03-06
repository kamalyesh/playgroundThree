#ifndef SceneSplashScreen_hpp
#define SceneSplashScreen_hpp

#include <SFML/Graphics.hpp>

#include "../ResourceAllocator.hpp"
#include "../SceneStateMachine.hpp"
#include "../WorkingDirectory.hpp"

class SceneSplashScreen : public Scene
{
public:
    SceneSplashScreen(WorkingDirectory &workingDir, SceneStateMachine &sceneStateMachine, Window &window, ResourceAllocator<sf::Texture>& textureAllocator);
    void OnCreate() override;
    void OnDestroy() override;

    void OnActivate() override;
    void OnDeactivate() override;

    void setSwitchToScene(unsigned int id);

    void Update(float deltaTimeFps) override;
    void Draw(Window &window) override;

private:
    ResourceAllocator<sf::Texture>& textureAllocator;
    sf::Sprite splashSprite;

    WorkingDirectory &workingDir;
    SceneStateMachine &sceneStateMachine;
    Window &window;

    // We want to show this scene for a set amount of time
    float showForSeconds;

    // How long the scene has currently been visible.
    float currentSeconds;

    // The state we want to transition to when this scenes time expires.
    unsigned int switchToState;
};
#endif /* SceneSplashScreen_hpp */