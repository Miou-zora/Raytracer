/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** SFMLDisplayer
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "IDisplayer.hpp"

namespace RayTracer {
    class SFMLDisplayer : virtual public RayTracer::IDisplayer {
        public:
            SFMLDisplayer(sf::RenderWindow &window) : m_window(window) {};
            ~SFMLDisplayer() = default;

            void display(const RayTracer::Frame &frame);

        protected:
        private:
            sf::RenderWindow &m_window;
    };
}
