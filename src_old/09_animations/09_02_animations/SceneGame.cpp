#include "SceneGame.hpp"
#include <iostream>
#define P(s) std::cout << s << std::endl;

SceneGame::SceneGame(WorkingDirectory &workingDirectory, ResourceAllocator<sf::Texture> &textureAllocator) : workingDir(workingDirectory), textureAllocator(textureAllocator)
{
    // P("SceneGame::SceneGame")
}

void SceneGame::OnCreate()
{
    // P(workingDir.Resources() + "texture/viking.png")
    std::shared_ptr<Object> player = std::make_shared<Object>();

    auto sprite = player->AddComponent<ComponentSprite>();
    sprite->SetTextureAllocator(&textureAllocator);

    auto movement = player->AddComponent<ComponentKeyboardMovement>();
    movement->SetInput(&input);

    auto animation = player->AddComponent<ComponentAnimation>();

    int vikingTextureID = textureAllocator.Add(workingDir.Textures() + "Viking.png");

    const int frameWidth = 165;  // manual, change later
    const int frameHeight = 145; // manual, change later

    std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>();

    // How long we want to show each frame.
    const float idleAnimFrameSeconds = 0.2f;

    idleAnimation->AddFrame(vikingTextureID, 600, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 800, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 0, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 200, 145, frameWidth, frameHeight, idleAnimFrameSeconds);

    // This adds the idle animation that we’ve just built.
    // It will also set it as our active animation.
    animation->AddAnimation(AnimationState::IDLE, idleAnimation);

    objects.Add(player);
}

void SceneGame::OnDestroy()
{
    // P("SceneGame::OnDestroy")
}

void SceneGame::ProcessInput()
{
    // P("SceneGame::ProcessInput")
    input.Update();
}

void SceneGame::Update(float deltaTimeFps)
{
    // P("SceneGame::Update")
    objects.ProcessRemovals();
    objects.ProcessNewObjects();

    objects.Update(deltaTimeFps);
}

void SceneGame::Draw(Window &window)
{
    // P("SceneGame::Draw")
    objects.Draw(window);
}

void SceneGame::LateUpdate(float deltaTimeFps)
{
    objects.LateUpdate(deltaTimeFps);
}