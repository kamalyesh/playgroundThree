#include "S_Drawable.hpp"

void SystemDrawable::Add(std::vector<std::shared_ptr<Object>>& objects)
{
    for (auto o : objects)
    {
        Add(o);
    }
    
    Sort();
}

void SystemDrawable::ProcessRemovals()
{
    auto objIterator = drawables.begin();
    while (objIterator != drawables.end())
    {
        auto obj = *objIterator;
        
        if (obj->IsQueuedForRemoval())
        {
            objIterator = drawables.erase(objIterator);
        }
        else
        {
            ++objIterator;
        }
    }
}

void SystemDrawable::Add(std::shared_ptr<Object> object)
{
    std::shared_ptr<ComponentDrawable> draw = object->GetDrawable();
    
    if (draw)
    {
        drawables.emplace_back(object);
    }
}

void SystemDrawable::Sort()
{
    std::sort(drawables.begin(), drawables.end(), [](std::shared_ptr<Object> a, std::shared_ptr<Object> b) -> bool
              {
                  return a->GetDrawable()->GetSortOrder() < b->GetDrawable()->GetSortOrder();
              });
}

void SystemDrawable::Draw(Window& window)
{
    for (auto& d : drawables)
    {
        d->Draw(window);
    }
}
