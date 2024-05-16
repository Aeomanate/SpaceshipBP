#include "MenuLayer.h"
#include "UI/Menus/BaseMenu.h"

BaseMenu* MenuLayer::TopMenu()
{
    return menuStack.top().get();
}

void MenuLayer::OnCloseMenuRequest()
{
    menuStack.pop();
}
