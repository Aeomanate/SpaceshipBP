#ifndef SPACESHIPBP_VECTORS_H
#define SPACESHIPBP_VECTORS_H

#include <SFML/System/Vector2.hpp>
#include "Utility/Visual/PositionInRectangle.h"

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


// Absolute actionOpt for each component
sf::Vector2f fabs(sf::Vector2f A);

// Compare less for each component
bool operator< (sf::Vector2f A, sf::Vector2f B);
inline const sf::Vector2f VECTOR_SEMI_ZERO = { 0.0001f, 0.0001f };

// Check less for each component with VECTOR_SEMI_ZERO
bool isSemiZero(sf::Vector2f A);

// Convert position in rectangle to a vector [0 ... 1; 0 ... 1]
sf::Vector2f toVector2f(PositionInRectagle positionInRectangle);

// Multiply vectors components
template <class T, class U, class CommonT = std::common_type_t<T, U>>
sf::Vector2<CommonT> operator*(sf::Vector2<T> A, sf::Vector2<U> B)
{
    return { A.x * B.x, A.y * B.y };
}


#endif //SPACESHIPBP_VECTORS_H
