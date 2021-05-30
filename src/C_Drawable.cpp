#include "C_Drawable.hpp"

ComponentDrawable::ComponentDrawable() : sortOrder(0){}

ComponentDrawable::~ComponentDrawable(){}

void ComponentDrawable::SetSortOrder(int order)
{
    sortOrder = order;
}

int ComponentDrawable::GetSortOrder() const
{
    return sortOrder;
}
