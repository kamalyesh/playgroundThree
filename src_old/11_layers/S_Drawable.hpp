#ifndef SystemDrawable_hpp
#define SystemDrawable_hpp

#include <map>

#include "C_Drawable.hpp"
#include "Object.hpp"

class SystemDrawable
{
public:
    void Add(std::vector<std::shared_ptr<Object>>& object);
    
    void ProcessRemovals();
    
    void Draw(Window& window);
    
private:
    void Add(std::shared_ptr<Object> object);
    void Sort();
    
    std::vector<std::shared_ptr<Object>> drawables;
    
};

#endif /* SystemDrawable_hpp */
