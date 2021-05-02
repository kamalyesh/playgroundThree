#ifndef SceneGame_hpp
#define SceneGame_hpp

#include <iostream>

#include "../Scene.hpp"
#include "../ResourceAllocator.hpp"
#include "../WorkingDirectory.hpp"
#include "../Components/ComponentSprite.hpp"
#include "../Components/ComponentKeyboardMovement.hpp"

class SceneGame : public Scene
{
public:
    SceneGame(WorkingDirectory &workingDir, ResourceAllocator<sf::Texture>& textureAllocator);
    void OnCreate() override;
    void OnDestroy() override;

    void ProcessInput() override;
    void Update(float deltaTimeFps) override;
    void Draw(Window &window) override;
    void LateUpdate(float deltaTimeFps) override;

private:
    std::shared_ptr<Object> player;
    ResourceAllocator<sf::Texture>& textureAllocator;

    WorkingDirectory &workingDir;
    Input input;

};
#endif /* SceneGame_hpp */