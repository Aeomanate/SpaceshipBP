// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by Lyosha12 on 07.03.2019.
//

#include <cmath>
#include "Vectors.hpp"
#include "../Random/Random.hpp"

float pseudoscalarProduction(sf::Vector2f A, sf::Vector2f B) {
    return A.x*B.y - A.y*B.x;
}
float scalarProduction(sf::Vector2f A, sf::Vector2f B) {
    return A.x * B.x + A.y * B.y;
}

float length(sf::Vector2f A) {
    return static_cast<float>(sqrt(A.x * A.x + A.y * A.y));
}

sf::Vector2f normalize(sf::Vector2f A) {
    float a_length = length(A);
    A.x /= a_length;
    A.y /= a_length;
    return A;
}

float angle(sf::Vector2f A, sf::Vector2f B) {
    float cos = scalarProduction(A, B) / (length(A) * length(B));
    float angle = static_cast<float>(acos(cos) * 180/M_PI);
    
    if((pseudoscalarProduction(A, B) > 0)) {
        angle = 360 - angle;
    }
    
    return angle; // Clockwise rotate degree.
}

sf::Vector2f randUnitVector() {
    return normalize(sf::Vector2f {
        static_cast<float>(pow(-1.0f, random() % 2) * (random() % 100)),
        static_cast<float>(pow(-1.0f, random() % 2) * (random() % 100))
    });
}