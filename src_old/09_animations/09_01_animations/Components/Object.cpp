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
    for (int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Awake();
    }
}

void Object::Start()
{
    // P("Object::Start ")
    for (int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Start();
    }
}

void Object::Update(float deltaTimeFps)
{
    // P("Object::Update " << deltaTimeFps)
    for (int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Update(deltaTimeFps);
    }
}

void Object::LateUpdate(float deltaTimeFps)
{
    // P("Object::LateUpdate " << deltaTimeFps)
    for (int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->LateUpdate(deltaTimeFps);
    }
}

void Object::Draw(Window &window)
{
    // P("Object::Draw")
    for (int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Draw(window);
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
