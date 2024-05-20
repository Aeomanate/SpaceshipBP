#ifndef SPACESHIPBP_VECTORS_H
#define SPACESHIPBP_VECTORS_H

#include <numbers>
#include "SFML/System/Vector2.hpp"
#include "Utility/Visual/PositionInRectangle.h"

// Pseudo scalar product
float pdot(sf::Vector2f A, sf::Vector2f B);

// Scalar product
float dot(sf::Vector2f A, sf::Vector2f B);

// Square of len
float len2(sf::Vector2f A);

// Vector len
float len(sf::Vector2f A);

// Make vector length equals to 1
sf::Vector2f norm(sf::Vector2f A);

// Angle between vectors, 360 degree
// angleDeg<Clockwise>({1, 0}, {1, 1}) == 315
// angleDeg<Clockwise>({1, 0}, {1, -1}) == 45
enum class RotationType { Clockwise, AntiClockwise };
template <RotationType ROTATION_TYPE = RotationType::AntiClockwise>
float angleDeg(sf::Vector2f A, sf::Vector2f B) {
    float cos = dot(A, B) / (len(A) * len(B));
    float angle = acosf(cos) * 180 / std::numbers::pi_v<float>;

    if constexpr (ROTATION_TYPE == RotationType::Clockwise)
    {
        if(pdot(A, B) > 0)
        {
            angle =  360 - angle;
        }
    }
    else if constexpr (ROTATION_TYPE == RotationType::AntiClockwise)
    {
        if(pdot(A, B) < 0)
        {
            angle =  360 - angle;
        }
    }

    return angle;
}

// Generate random vector with length equals to 1
sf::Vector2f randUnitVector();


// Absolute actionOpt for each component
sf::Vector2f abs(sf::Vector2f A);

// Compare less for each component
bool operator< (sf::Vector2f A, sf::Vector2f B);

// Check less for each component with EPS components
inline const float EPS = 0.001f;
bool isSemiZero(float value, float epsVal);
bool isSemiZero(float value);
bool isSemiZero(sf::Vector2f A, sf::Vector2f epsValue);
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
