/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** PositionSystem
*/

#include "System.hpp"
#include <math.h>

# define M_PI		3.14159265358979323846	/* pi */
# define M_RAD      M_PI / 180 /* radian */
# define MULTIPLY   1

namespace User {

    constexpr double degreeToRadian(double deg)
    {
        return (deg * M_RAD);
    }

    void moveSystem(Registry_ref reg, Window_ref window)
    {
        auto &draw = reg.get_components<drawable>();
        auto &comp = reg.get_components<compass>();

        sf::Vector2f save{0, 0};

        for (int i = 0; i < comp.size() && i < draw.size(); i++) {
            if (comp[i]) {
                // set o(mid circle point) to the last circle point
                if (i != 0)
                    comp[i]->o = save;
                // calcul trigo point from degree and last point
                comp[i]->degree += comp[i]->velocity;

                comp[i]->p = sf::Vector2f(comp[i]->o.x + (comp[i]->size * MULTIPLY * cos(degreeToRadian(comp[i]->degree))) ,
                                          comp[i]->o.y + (comp[i]->size * MULTIPLY * sin(degreeToRadian(comp[i]->degree))) );
                save = comp[i]->p;
            }
        }

    }

    void displaySystem(Registry_ref reg, Window_ref window)
    {
        auto &draw = reg.get_components<drawable>();
        auto &comp = reg.get_components<compass>();


        sf::Vector2f midle = { static_cast<float>(sf::VideoMode::getDesktopMode().width / 2),
                                static_cast<float>(sf::VideoMode::getDesktopMode().height / 2) };

        for (int i = 0; i < draw.size() && i < comp.size() ; ++i) {
            if (draw[i] && comp[i]) {

                sf::Vertex point(midle + comp[i]->o, sf::Color::White);
                std::cout << "point: "<< point.position.x << " " << point.position.y << std::endl;
                sf::Vertex circle(point.position +  comp[i]->p, sf::Color::White);

                std::cout << "circle: " << circle.position.x << " " << circle.position.y << std::endl;
//                window.draw(&point, 1, sf::Points);
                window.draw(&circle, 1, sf::Points);
            }
        }
    }
};