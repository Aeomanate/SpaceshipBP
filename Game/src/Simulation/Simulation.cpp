#include "Simulation.h"
#include "Core/Application/ApplicationShortcuts.h"
#include <iostream>

Simulation::Simulation()
{

}

void Simulation::Init()
{
    currentLevel = getLevelProvider().LoadLevel(getConfig().simulation.levels)
}

void Simulation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

void Simulation::OnKeyPressed(const sf::Event::KeyEvent&)
{
    std::cout << "simulation key pressed\n";

}

void Simulation::OnMouseButtonClicked(const sf::Event::MouseButtonEvent&)
{
    std::cout << "simulation mouse clicked\n";
}

void Simulation::Update(float dt)
{

}
