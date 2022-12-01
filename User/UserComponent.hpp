/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-zacharie.lawson
** File description:
** Component
*/

#ifndef USER_COMPONENT_HPP_
    #define USER_COMPONENT_HPP_

    #include "SFML/Window.hpp"
    #include "SFML/Graphics.hpp"
    #include "SFML/Audio.hpp"
    #include "SFML/System.hpp"

    #include <functional>

//utilisateur


struct compass {
    sf::Vector2f o;
    double degree;
    double size;
    double velocity;
    sf::Vector2f p;
};

struct visibility {
    bool visible;
};

struct drawable {
    sf::Vertex vertex;
};


#endif /* !USER_COMPONENT_HPP_ */
