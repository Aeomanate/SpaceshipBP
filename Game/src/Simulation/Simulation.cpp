#include "Simulation.h"

#include "Core/Application/ApplicationShortcuts.h"
#include "Core/Application/Application.h"
#include "Simulation/GameLevels/Base/Level.h"
#include "ECS/Features/Input/SInputInjector.h"

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

    moveBinding.try_emplace(getConfig().simulation.keys.up, sf::Vector2f{0, -1});
    moveBinding.try_emplace(getConfig().simulation.keys.down, sf::Vector2f{0, 1});
    moveBinding.try_emplace(getConfig().simulation.keys.left, sf::Vector2f{-1, 0});
    moveBinding.try_emplace(getConfig().simulation.keys.right, sf::Vector2f{1, 0});
}

void Simulation::Update(float dt)
{
    currentLevel->Update(dt);
}

void Simulation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*currentLevel, states);
}

void Simulation::OnKeyPressed(const sf::Event::KeyEvent& e)
{
    auto it = moveBinding.find(e.code);
    if(it == moveBinding.end())
    { return; }

    Log(getLoc().simulation.playerMovingVerbose, "Inject movement, pressed: " + toString(it->second), Logger::Level::VERBOSE);
    currentLevel->GetInputInjector().InjectMovement(it->second);
}

void Simulation::OnKeyReleased(const sf::Event::KeyEvent& e)
{
    auto it = moveBinding.find(e.code);
    if(it == moveBinding.end())
    { return; }

    Log(getLoc().simulation.playerMovingVerbose, "Inject movement, released: " + toString(it->second), Logger::Level::VERBOSE);
    currentLevel->GetInputInjector().InjectMovement(- it->second);
}

void Simulation::OnMouseButtonClicked(const sf::Event::MouseButtonEvent& e)
{
    currentLevel->GetInputInjector().InjectMouseClick(sf::Vector2f(sf::Vector2i{ e.x, e.y }));
}

void Simulation::OnMouseMoved(const sf::Vector2i& newPos)
{
    currentLevel->GetInputInjector().InjectMousePosition(sf::Vector2f(newPos));
}
