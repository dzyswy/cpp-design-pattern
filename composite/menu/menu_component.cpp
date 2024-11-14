#include "menu_component.h"







MenuComponent* MenuItem::move_left() 
{
    MenuBar* bar = (MenuBar*)parent();
    return bar->find_left_child(this);
}

MenuComponent* MenuItem::move_right() 
{
    MenuBar* bar = (MenuBar*)parent();
    return bar->find_right_child(this);
}










