#ifndef SPACESHIPBP_APPLICATION_H
#define SPACESHIPBP_APPLICATION_H

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Core/EventsHandling/ListenersEmitters.h"
#include "Simulation/Simulation.h"
#include "Utility/Singleton.h"
#include "LowLevelApplication.h"
#include "Core/GameLayers/MenuLayer.h"
#include "Core/Storage/RootLocalization.h"
#include "Core/Storage/RootConfig.h"
#include "Utility/Visual/TextureProvider.h"
#include "Utility/Math/Random.h"
#include "Simulation/GameLevels/Base/LevelProvider.h"

class Application: public LowLevelApplication, public Singleton<Application>
{
    friend class Singleton<Application>;

public:
    Application& Init() override;

public:
    static MenuLayer& GetMenuLayer();
    static const Simulation& GetSimulation();
    static const GeneralConfig& GetConfig();
    static const GeneralLocalization& GetLoc();
    static const TextureProvider& GetTextureProvider();
    static LevelProvider& GetLevelProvider();
    static Random& GetRnd();

private: // Game-related methods
    void Draw() override;
    void Update() override;
    void FinishWork() override;

private: // Listeners
    SIMPLE_LISTENER(LastMenuClosed);
    DATA_LISTENER(KeyPressed, sf::Event::KeyEvent);

protected:
    void InitListeners();
    void InitStorages();
    void InitGameRelated();

private: // Game-related objects
    MenuLayer menuLayer;
    Simulation simulation;
    TextureProvider textureProvider;
    LevelProvider levelProvider;
    Random random;

    RootConfig rootConfig;
    RootLocalization rootLocalization;
};

#endif
