#include "Object.hpp"
#include <iostream>
#define P(s) std::cout << s << std::endl;

Object::Object() : queuedForRemoval(false)
{
    transform = AddComponent<ComponentTransform>();
}

void Object::Awake()
{
    // P("Object::Awake")
    for (auto& c : components)
    {
        c->Awake();
    }
}

void Object::Start()
{
    // P("Object::Start ")
    for (auto& c : components)
    {
        c->Start();
    }
}

void Object::Update(float deltaTimeFps)
{
    // P("Object::Update " << deltaTimeFps)
    for (const auto& component : components)
    {
        component->Update(deltaTimeFps);
    }
}

void Object::LateUpdate(float deltaTimeFps)
{
    // P("Object::LateUpdate " << deltaTimeFps)
    for (const auto& component : components)
    {
        component->LateUpdate(deltaTimeFps);
    }
}

void Object::Draw(Window &window)
{
    // P("Object::Draw")
    for (const auto& component : components)
    {
        component->Draw(window);
    }
}

void Object::QueueForRemoval()
{
    queuedForRemoval = true;
}

bool Object::IsQueuedForRemoval()
{
    return queuedForRemoval;
}
