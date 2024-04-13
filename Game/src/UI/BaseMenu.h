#ifndef SPACESHIPBP_BASEMENU_H
#define SPACESHIPBP_BASEMENU_H

#include "Utility/EventsHandling/ListenersEmitters.h"

class BaseMenu
{
public:
    EventEmitter<void> closeEvent;

private:
};


#endif //SPACESHIPBP_BASEMENU_H
