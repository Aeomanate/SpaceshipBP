#include "MenuLayer.h"
#include "UI/Menus/BaseMenu.h"

MenuLayer::MenuLayer()
{

}

BaseMenu* MenuLayer::TopMenu()
{
    return menuStack.top().get();
}

void MenuLayer::OnCloseMenuRequest()
{
    menuStack.pop();
}
