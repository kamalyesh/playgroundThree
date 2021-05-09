#ifndef SceneGame_hpp
#define SceneGame_hpp

#include <iostream>

#include "Input.hpp"
#include "Object.hpp"
#include "Scene.hpp"
#include "ResourceAllocator.hpp"
#include "WorkingDirectory.hpp"
#include "ComponentAnimation.hpp"
#include "ComponentSprite.hpp"
#include "ComponentKeyboardMovement.hpp"
#include "ObjectCollection.hpp"

class SceneGame : public Scene
{
public:
    SceneGame(WorkingDirectory &workingDir, ResourceAllocator<sf::Texture> &textureAllocator);
    void OnCreate() override;
    void OnDestroy() override;

    void ProcessInput() override;
    void Update(float deltaTimeFps) override;
    void Draw(Window &window) override;
    void LateUpdate(float deltaTimeFps) override;

private:
    // std::shared_ptr<Object> player;
    ResourceAllocator<sf::Texture> &textureAllocator;
    WorkingDirectory &workingDir;
    Input input;
    ObjectCollection objects;
};
#endif /* SceneGame_hpp */