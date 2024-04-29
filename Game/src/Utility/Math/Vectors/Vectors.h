#ifndef SPACESHIPBP_VECTORS_H
#define FUSEGAME_VECTORS_HPP

#include <SFML/System/Vector2.hpp>

// Scalar product
float dot(sf::Vector2f A, sf::Vector2f B);

// Square of len
float len2(sf::Vector2f A);

// Vector len
float len(sf::Vector2f A);

// Make vector length equals to 1
sf::Vector2f norm(sf::Vector2f A);

// Angle between vectors, 360 degree
float angleDeg(sf::Vector2f A, sf::Vector2f B);

// Generate random vector with length equals to 1
sf::Vector2f randUnitVector();


// Absolute value for each component
sf::Vector2f fabs(sf::Vector2f A);
inline const sf::Vector2f VECTOR_SEMI_ZERO = { 0.0001f, 0.0001f };

// Compare less for component
bool operator< (sf::Vector2f A, sf::Vector2f B);

#endif //SPACESHIPBP_VECTORS_H
