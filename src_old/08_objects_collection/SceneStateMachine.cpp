#include "./SceneStateMachine.hpp"
#include <iostream>
#define P(s) std::cout << s << std::endl;
SceneStateMachine::SceneStateMachine() : scenes(0), curScene(0)
{
    // insertedSceneID = 0;
}

void SceneStateMachine::ProcessInput()
{
    // P("Process Input");
    if (curScene)
    {
        curScene->ProcessInput();
    }
    else
    {
        // P("not curScene")
    }
}

void SceneStateMachine::Update(float deltaTimeFps)
{
    // P("Update " << deltaTimeFps);
    if (curScene)
    {
        curScene->Update(deltaTimeFps);
    }
    else
    {
        // P("not curScene")
    }
}

void SceneStateMachine::LateUpdate(float deltaTimeFps)
{
    // P("Late Update " << deltaTimeFps);
    if (curScene)
    {
        curScene->LateUpdate(deltaTimeFps);
    }
    else
    {
        // P("not curScene")
    }
}

void SceneStateMachine::Draw(Window &window)
{
    // P("Draw");
    if (curScene)
    {
        curScene->Draw(window);
    }
}

unsigned int SceneStateMachine::Add(std::shared_ptr<Scene> scene)
{
    // P("Add " << insertedSceneID);
    auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));
    // P("inserted " << insertedSceneID);
    inserted.first->second->OnCreate();
    // P("creating " << insertedSceneID << " scene");
    return insertedSceneID++;
}

void SceneStateMachine::Remove(unsigned int id)
{
    // P("Remove " << id);
    auto it = scenes.find(id);
    // P("it found")
    if (it != scenes.end())
    {
        // P("it not last")
        if (curScene == it->second)
        {
            // P("it is current")
            curScene = nullptr;
        }
        else
        {
            // P("not curScene")
        }
    }
    // P("destroying it")
    it->second->OnDestroy();
    // P("erasing it")
    scenes.erase(it);
}

void SceneStateMachine::SwitchTo(unsigned int id)
{
    // P("Switch to " << id);
    auto it = scenes.find(id);
    // P("it found")
    if (it != scenes.end())
    {
        // P("it not last")
        if (curScene)
        {
            // P("it is current")
            // P("deactivate it")
            // If we have a current scene, we call its OnDeactivate method.
            curScene->OnDeactivate();
        }
        else
        {
            // P("not curScene")
        }
        // P("switching it to " << id)
        // Setting the current scene ensures that it is updated and drawn.
        curScene = it->second;
        // P("activating it")
        curScene->OnActivate();
    }
}