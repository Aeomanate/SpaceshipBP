#ifndef SPACESHIPBP_MENUMANAGER_H
#define SPACESHIPBP_MENUMANAGER_H

#include <stack>
#include <memory>

#include "Utility/EventsHandling/ListenersEmitters.h"
#include "UI/BaseMenu.h"

class MenuManager
{
public:
    MenuManager();

    template <class MenuType>
    void SpawnMenu();

    BaseMenu* TopMenu();

public: // Emitters
    EventEmitter<void> emitterLastMenuClosed;

private: // Event handlers
    void OnMenuClosed();

private:
    std::stack<std::unique_ptr<BaseMenu>> menuStack;

    EventListener<void> listenerCloseMenu;
};

#include "TemplateSpecializes.h"

#endif //SPACESHIPBP_MENUMANAGER_H
