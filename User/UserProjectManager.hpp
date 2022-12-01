/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-zacharie.lawson
** File description:
** ProjectManager
*/

#ifndef USER_PROJECT_MANAGER_HPP_
    #define USER_PROJECT_MANAGER_HPP_

    #include <fstream>
    //Std
    #include <tuple>
    #include <type_traits> //std::is_same_v
    #include <iostream>

    //sfml
    #include "SFML/Window.hpp"
    #include "SFML/Graphics.hpp"
    #include "SFML/Audio.hpp"
    #include "SFML/System.hpp"

    //ProjectManager
    #include "ProjectManager.hpp"
    #include "Ecs.hpp"

    //User
    #include "UserManager.hpp"
    #include "UserComponentManager.hpp"

/**
 * @namespace Project
 *
 * @author perry.chouteau@epitech.eu
 */
namespace User {

    using Window_ref = sf::RenderWindow &;
    using Event_ref = sf::Event &;

    /**
     * @brief UserProjectManager
     *
     * @author perry.chouteau@epitech.eu
     */
    class UserProjectManager final : public Project::ProjectManager {
        public:

            /**
             * @brief Construct a Project Manager using c++ inheritance folowing User needs !
             *
             * @param jsonfile
             */
            UserProjectManager()
            : ProjectManager(), _window(CreateMyWindow()), _userManager()
            {                //User
                config_extractor<user_config::components_list>::function(_ecs); //user

                InitWindow();
            }

            /**
             * @brief Destroy the User Project Manager
             *
             */
            ~UserProjectManager() = default;

            /**
             * @brief Start our Client
             *
             * @param ip
             * @param port
             * @return int
             */
            int Start()
            {
                _userManager.InitSystem(_ecs, _window);
                while (_window.isOpen()) {
                    _userManager.UpdateSystem(_ecs, _window);
                    while (_window.pollEvent(_event)) {
                        if (_event.type == sf::Event::Closed) {
                            _window.close();
                            break;
                        }
                    _userManager.EventSystem(_ecs, _event, _window);
                    }
                    _userManager.DisplaySystem(_ecs, _window);
                    _window.display();
//                    _window.clear();
                }
                return 0;
            };

////////////////////////////////////////////////////////////////////////////////////////////////

        private:

            /**
             * @brief Create Window from json file
             *
             * @return sf::RenderWindow
             */
            sf::RenderWindow CreateMyWindow()
            {
                    return sf::RenderWindow(sf::VideoMode(1900, 1080),
                            std::string("my_hunter"));
            }

            void InitWindow()
            {
                _window.setFramerateLimit(60);
            }

        private:
            User::UserManager _userManager;

            //sfml
            sf::RenderWindow _window;
            sf::Event _event;
    };

};

#endif /* !USER_PROJECT_MANAGER_HPP_ */
