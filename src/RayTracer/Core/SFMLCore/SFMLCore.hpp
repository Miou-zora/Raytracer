/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** SFMLCore
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "ICore.hpp"
#include <memory>

namespace RayTracer {
    class SFMLCore : virtual public ICore {
        public:
            SFMLCore(const std::pair<int, int> &windowSize);
            ~SFMLCore();

            void init(void);

            void run(void);

        protected:
        private:
            bool _isRunning;
            std::pair<int, int> _windowSize;
            sf::RenderWindow _window;
            sf::VideoMode _videoMode;

            void createWindow(void);
            void closeWindow(void);
    };
}
