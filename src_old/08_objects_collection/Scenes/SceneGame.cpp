#include "SceneGame.hpp"
#include <iostream>
#define P(s) std::cout << s << std::endl;

SceneGame::SceneGame(WorkingDirectory &workingDirectory, ResourceAllocator<sf::Texture> &textureAllocator)
    : workingDir(workingDirectory), textureAllocator(textureAllocator)
{
    // P("SceneGame::SceneGame")
}

void SceneGame::OnCreate()
{
    // P(workingDir.Resources() + "texture/viking.png")
    std::shared_ptr<Object> player = std::make_shared<Object>();

    auto sprite = player->AddComponent<ComponentSprite>();
    sprite->SetTextureAllocator(&textureAllocator);
    sprite->Load(workingDir.Resources() + "texture/viking.png");

    auto movement = player->AddComponent<ComponentKeyboardMovement>();
    // Don’t forget to set the input otherwise the character will not move:
    movement->SetInput(&input);

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