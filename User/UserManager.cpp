/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-zacharie.lawson
** File description:
** User
*/

#include "UserManager.hpp"

void User::UserManager::InitSystem(Registry_ref _ecs, Window_ref window)
{
    entity_t circle = _ecs.spawn_entity();
        _ecs.add_component<compass>(circle, {sf::Vector2f(0, 0), 0, 100, 1});

//    entity_t circle2 = _ecs.spawn_entity();
//    _ecs.add_component<compass>(circle2, {sf::Vector2f(0, 0), 0, 100, -2});
//    _ecs.add_component<drawable>(circle2, {});

    entity_t circle3 = _ecs.spawn_entity();
    _ecs.add_component<compass>(circle3, {sf::Vector2f(0, 0), 0, 50, 4});

//    entity_t circle3 = _ecs.spawn_entity();
//    _ecs.add_component<compass>(circle3, {sf::Vector2f(0, 0), 0, 50, -4});

    entity_t circle2 = _ecs.spawn_entity();
    _ecs.add_component<compass>(circle2, {sf::Vector2f(0, 0), 0, 0, 0});
    _ecs.add_component<drawable>(circle2, {});

/*    _ecs.add_component<position>(circle, position{0, 0});
    _ecs.add_component<velocity>(circle, velocity{-1});
    _ecs.add_component<degree>(circle, degree{0});
    _ecs.add_component<sizable>(circle, sizable{2});
    _ecs.add_component<drawable>(circle, drawable{});*/

}

void User::UserManager::UpdateSystem(Registry_ref _ecs, Window_ref _window)
{
    User::moveSystem(_ecs, _window);
}

void User::UserManager::EventSystem(Registry_ref _ecs, Event_ref _event, Window_ref _window)
{
}

void User::UserManager::DisplaySystem(Registry_ref _ecs, Window_ref _window)
{
    User::displaySystem(_ecs, _window);
}