#ifndef ObjectCollection_hpp
#define ObjectCollection_hpp

#include <memory>
#include <vector>

#include "Object.hpp"

class ObjectCollection
{
public:
    void Add(std::shared_ptr<Object> object);

    void Update(float deltaTimeFps);
    void LateUpdate(float deltaTimeFps);
    void Draw(Window &window);

    void ProcessNewObjects();
    void ProcessRemovals();

private:
    std::vector<std::shared_ptr<Object>> objects;
    std::vector<std::shared_ptr<Object>> newObjects;
};

#endif /* ObjectCollection_hpp */
