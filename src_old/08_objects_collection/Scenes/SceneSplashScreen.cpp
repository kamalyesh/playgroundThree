#include "./SceneSplashScreen.hpp"

#include <iostream>
#define P(s) std::cout << s << std::endl;

SceneSplashScreen::SceneSplashScreen(WorkingDirectory &workingDir, SceneStateMachine &sceneStateMachine, Window &window, ResourceAllocator<sf::Texture> &textureAllocator)
    : sceneStateMachine(sceneStateMachine), workingDir(workingDir), window(window), switchToState(0), currentSeconds(0.f), showForSeconds(3.f), textureAllocator(textureAllocator)
{
    // P("SceneSplashScreen::SceneSplashScreen")
}

void SceneSplashScreen::OnCreate()
{
    // P("SceneSplashScreen::OnCreate")
    int textureID = textureAllocator.Add(workingDir.Resources() + "texture/wall.png");

    if (textureID >= 0)
    {
        std::shared_ptr<sf::Texture> texture = textureAllocator.Get(textureID);
        splashSprite.setTexture(*texture);

        sf::FloatRect spriteSize = splashSprite.getLocalBounds();
        // Set the origin of the sprite to the centre of the image:
        splashSprite.setOrigin(spriteSize.width * 0.5f, spriteSize.height * 0.5f);
        // splashSprite.setScale(0.5f, 0.5f);

        sf::Vector2u windowCentre = window.GetCentre();
        // Positions sprite in centre of screen:
        splashSprite.setPosition(windowCentre.x, windowCentre.y);
    }
}

void SceneSplashScreen::OnActivate()
{
    // P("SceneSplashScreen::OnActivate")
    currentSeconds = 0.f;
}

void SceneSplashScreen::OnDeactivate()
{
}

void SceneSplashScreen::OnDestroy()
{
    // P("SceneSplashScreen::OnDestroy")
}

void SceneSplashScreen::setSwitchToScene(unsigned int id)
{
    // P("SceneSplashScreen::setSwitchToScene " << id)
    switchToState = id;
}

void SceneSplashScreen::Update(float deltaTimeFps)
{
    // P("SceneSplashScreen::Update " << deltaTimeFps)
    // if (currentSeconds < showForSeconds) {
    currentSeconds += deltaTimeFps;
    // }
    float diff = currentSeconds - showForSeconds;
    // P("SceneSplashScreen::Update currentSeconds (" << currentSeconds << " >= " << showForSeconds << ") is " << (diff >= 0.f))
    if (diff >= 0.f)
    {
        sceneStateMachine.SwitchTo(switchToState);
    }
}

void SceneSplashScreen::Draw(Window &window)
{
    // P("SceneSplashScreen::Draw")
    window.Draw(splashSprite);
}