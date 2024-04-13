#ifndef SPACESHIPBP_TEMPLATESPECIALIZES_H
#define SPACESHIPBP_TEMPLATESPECIALIZES_H

template <class MenuType>
void MenuManager::SpawnMenu()
{
    menuStack.push(std::make_unique<MenuType>());
    listenerCloseMenu.SubscribeEmitter(menuStack.top()->closeEmitter);
}

#endif //SPACESHIPBP_TEMPLATESPECIALIZES_H
