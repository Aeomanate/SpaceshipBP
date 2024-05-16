#include "Simulation.h"

#include "Core/Application/Getters/LogGetter.h"
#include "Core/Application/Getters/LevelProviderGetter.h"
#include "Core/Application/Application.h"
#include "ECS/Features/Input/SInputInjector.h"
#include "Simulation/GameLevels/Base/Level.h"
#include "Simulation/Features/Timer/CTimer.h"
#include "Utility/Math/Math.h"

Simulation::Simulation()
{

}

void Simulation::Init()
{
    currentLevel = getLevelProvider().LoadLevel(getConfig().simulation.configLevels.level1);

    listenerKeyPressed.SubscribeEmitter(Application::GetInstance().emitterKeyPressed);
    listenerKeyReleased.SubscribeEmitter(Application::GetInstance().emitterKeyReleased);
    listenerMouseButtonClicked.SubscribeEmitter(Application::GetInstance().emitterMouseClicked);
    listenerMouseMoved.SubscribeEmitter(Application::GetInstance().emitterMouseMoved);

    moveVectors.try_emplace(getConfig().simulation.keys.up, sf::Vector2f{ 0, -1}); //-V807
    moveVectors.try_emplace(getConfig().simulation.keys.down, sf::Vector2f{ 0, 1});
    moveVectors.try_emplace(getConfig().simulation.keys.left, sf::Vector2f{ -1, 0});
    moveVectors.try_emplace(getConfig().simulation.keys.right, sf::Vector2f{ 1, 0});
}

void Simulation::Update(float dt)
{
    assert(currentLevel);

    float simElapsedSec = REF(CTimer::TryGetFirstDataPtr());

    float realElapsedSec = clockRealtime.getElapsedTime().asSeconds();
    if(realElapsedSec <= simElapsedSec)
    { return; }

    REF(currentLevel).Update(dt);
}

void Simulation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(REF(currentLevel), states);
}

void Simulation::OnKeyPressed(const sf::Event::KeyEvent& e)
{
    auto it = moveVectors.find(e.code);
    if(it == moveVectors.end())
    { return; }

    Log(getLoc().simulation.playerMovingVerbose,
        std::format("Inject movement, pressed: {}", toString(it->second)),
        Logger::Level::VERBOSE);

    currentLevel->GetInputInjector().InjectMoveVector(it->second);
}

void Simulation::OnKeyReleased(const sf::Event::KeyEvent& e)
{
    auto it = moveVectors.find(e.code);
    if(it == moveVectors.end())
    { return; }

    Log(getLoc().simulation.playerMovingVerbose,
        std::format("Inject movement, released: {}", toString(it->second)),
        Logger::Level::VERBOSE);

    currentLevel->GetInputInjector().InjectMoveVector(-it->second);
}

void Simulation::OnMouseButtonClicked(const sf::Event::MouseButtonEvent& e)
{
    currentLevel->GetInputInjector().InjectMouseClick(sf::Vector2f(sf::Vector2i{ e.x, e.y }));
}

void Simulation::OnMouseMoved(const sf::Vector2i& newPos)
{
    currentLevel->GetInputInjector().InjectMousePosition(sf::Vector2f(newPos));
}
