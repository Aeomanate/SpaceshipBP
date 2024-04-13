#ifndef SPACESHIPBP_APPLICATION_H
#define SPACESHIPBP_APPLICATION_H

#include <unordered_map>
#include "SFML/Graphics.hpp"
#include "Core/EventsHandling/ListenersEmitters.h"
#include "Simulation/Simulation.h"
#include "Utility/Singleton.h"
#include "LowLevelApplication.h"
#include "Core/Config/Config.h"
#include "Core/MenuManager/MenuManager.h"

class Application: public LowLevelApplication, public Singleton<Application>
{
    friend class Singleton<Application>;
public:
    static MenuManager& GetMenuManager();
    static Simulation const& GetSimulation();
    static Config const& GetConfig();

private: // Game-related methods
    void Draw() override;
    void Update() override;

private: // Listeners
    SIMPLE_LISTENER(LastMenuClosed);

private: // Game-related objects
    MenuManager menuManager;
    Simulation simulation;
    Config config;

protected:
    Application();

};

#endif
