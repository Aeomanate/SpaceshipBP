//
// Created by Lyosha12 on 07.03.2019.
//

#ifndef FUSEGAME_VECTORS_HPP
#define FUSEGAME_VECTORS_HPP

#include <SFML/System/Vector2.hpp>

float scalarProduction(sf::Vector2f A, sf::Vector2f B);
float length(sf::Vector2f A);
sf::Vector2f normalize(sf::Vector2f A);
float angle(sf::Vector2f A, sf::Vector2f B);
sf::Vector2f randUnitVector();

#endif //FUSEGAME_VECTORS_HPP
