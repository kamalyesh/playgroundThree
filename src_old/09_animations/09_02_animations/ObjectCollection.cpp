#include "ObjectCollection.hpp"

void ObjectCollection::Add(std::shared_ptr<Object> object)
{
    newObjects.push_back(object);
}

void ObjectCollection::Update(float deltaTimeFps)
{
    for (auto &o : objects)
    {
        o->Update(deltaTimeFps);
    }
}

void ObjectCollection::LateUpdate(float deltaTimeFps)
{
    for (auto &o : objects)
    {
        o->LateUpdate(deltaTimeFps);
    }
}

void ObjectCollection::Draw(Window &window)
{
    for (auto &o : objects)
    {
        o->Draw(window);
    }
}

void ObjectCollection::ProcessNewObjects()
{
    if (newObjects.size() > 0)
    {
        for (const auto &o : newObjects)
        {
            o->Awake();
        }

        for (const auto &o : newObjects)
        {
            o->Start();
        }

        objects.assign(newObjects.begin(), newObjects.end());

        newObjects.clear();
    }
}

void ObjectCollection::ProcessRemovals()
{
    auto objIterator = objects.begin();
    while (objIterator != objects.end())
    {
        auto obj = **objIterator;

        if (obj.IsQueuedForRemoval())
        {
            objIterator = objects.erase(objIterator);
        }
        else
        {
            ++objIterator;
        }
    }
}
