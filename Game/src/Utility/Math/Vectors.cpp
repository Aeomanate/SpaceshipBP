#include <numbers>
#include <cmath>
#include <cassert>
#include "Vectors.h"
#include "Core/Application/ObjectsAggregator/GetterRandom.h"

// Pseudo scalar product
float pdot(sf::Vector2f A, sf::Vector2f B) {
    return A.x*B.y - A.y*B.x;
}

float dot(sf::Vector2f A, sf::Vector2f B) {
    return A.x * B.x + A.y * B.y;
}

float len2(sf::Vector2f A)
{
    return A.x * A.x + A.y * A.y;
}

float len(sf::Vector2f A) {
    return std::sqrt(len2(A));
}

sf::Vector2f norm(sf::Vector2f A) {
    assert(!isSemiZero(A));

    float a_length = len(A);
    A.x /= a_length;
    A.y /= a_length;
    return A;
}

float angleDeg(sf::Vector2f A, sf::Vector2f B) {
    float cos = dot(A, B) / (len(A) * len(B));
    float angle = acosf(cos) * 180 / std::numbers::pi_v<float>;

    if(pdot(A, B) > 0)
    {
        angle = 360 - angle;
    }

    return angle; // Clockwise rotate degree.
}

sf::Vector2f randUnitVector() {
    float signX = getRand().Range(0, 2) ? 1.0f : -1.0f;
    float signY = getRand().Range(0, 2) ? 1.0f : -1.0f; //-V656

    return norm(
        sf::Vector2f {
            signX * getRand().Range(0, 100.f),
            signY * getRand().Range(0, 100.f)
        });
}

sf::Vector2f abs(sf::Vector2f A)
{
    return sf::Vector2f { fabsf(A.x), fabsf(A.y) };
}

bool operator< (sf::Vector2f A, sf::Vector2f B)
{
    return A.x < B.x && A.y < B.y;
}

bool isSemiZero(float value, float epsVal)
{
    return std::abs(value) < epsVal;
}
bool isSemiZero(float value)
{
    return isSemiZero(value, EPS);
}
bool isSemiZero(sf::Vector2f A, sf::Vector2f epsValue)
{
    return abs(A) < epsValue;
}
bool isSemiZero(sf::Vector2f A)
{
    return isSemiZero(A, { EPS, EPS });
}

sf::Vector2f toVector2f(PositionInRectagle positionInRectangle)
{
    static sf::Vector2f map[] {
        {0, 0  }, {0.5,  0 }, {1,  0 },
        {0, 0.5}, {0.5, 0.5}, {1, 0.5},
        {0, 1  }, {0.5,  1 }, {1,  1 }
    };

    return map[positionInRectangle];
}
