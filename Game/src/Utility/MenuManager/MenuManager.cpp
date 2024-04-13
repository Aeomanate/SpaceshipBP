#include "MenuManager.h"
#include "UI/BaseMenu.h"

MenuManager::MenuManager()
: listenerCloseMenu { [this] { OnMenuClosed(); } }
{

}

void MenuManager::OnMenuClosed()
{
    menuStack.pop();
}

BaseMenu* MenuManager::TopMenu()
{
    return menuStack.top().get();
}
