#include "MenuManager.h"
#include "UI/Menus/BaseMenu.h"

MenuManager::MenuManager()
{

}

BaseMenu* MenuManager::TopMenu()
{
    return menuStack.top().get();
}

void MenuManager::OnCloseMenuRequest()
{
    menuStack.pop();

}
