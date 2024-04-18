#include "Simulation.h"
#include <iostream>

Simulation::Simulation()
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
