#include "Simulation.h"
#include <iostream>

Simulation::Simulation()
{

}

void Simulation::OnKeyPressed(const sf::Event::KeyEvent&)
{
    std::cout << "Simulation key pressed\n";

}

void Simulation::OnMouseButtonClicked(const sf::Event::MouseButtonEvent&)
{
    std::cout << "Simulation mouse clicked\n";
}
