
#ifndef ComponentDrawable_hpp
#define ComponentDrawable_hpp

#include <SFML/Graphics.hpp>

#include "Window.hpp"

class ComponentDrawable
{
public:
    ComponentDrawable();
    virtual ~ComponentDrawable();
    
    virtual void Draw(Window& window) = 0;
    
    void SetSortOrder(int order);
    int GetSortOrder() const;
    
private:
    int sortOrder;
};



#endif /* ComponentDrawable_hpp */
