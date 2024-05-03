#include "Simulation.h"

#include "Core/Application/ApplicationShortcuts.h"
#include "Simulation/Levels/Base/Level.h"

Simulation::Simulation()
{

}

void Simulation::Init()
{
    currentLevel = getLevelProvider().LoadLevel(getConfig().simulation.configLevels.level1);
}

void Simulation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*currentLevel, states);
}

void Simulation::OnKeyPressed(const sf::Event::KeyEvent&)
{

}

void Simulation::OnMouseButtonClicked(const sf::Event::MouseButtonEvent&)
{

}

void Simulation::Update(float dt)
{
    currentLevel->Update(dt);
}
