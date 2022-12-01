/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** System
*/

#ifndef SYSTEM_HPP_
    #define SYSTEM_HPP_

    #include "Ecs.hpp"

    #include "UserComponent.hpp"

    #include "SfmlRef.hpp"

//! Namespace for all game related content, here systems
namespace User {
    void moveSystem(Registry_ref reg, Window_ref window);

    void displaySystem(Registry_ref reg, Window_ref window);

}

#endif /* !SYSTEM_HPP_ */
