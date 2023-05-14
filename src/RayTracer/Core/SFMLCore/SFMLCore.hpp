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
#include "Scene.hpp"
#include "IRenderer.hpp"
#include "IDisplayer.hpp"

namespace RayTracer {
    class SFMLCore : virtual public ICore {
        public:
            SFMLCore();
            ~SFMLCore();

            void build(std::string scenePath, std::string flag = "-f");
            void run(void);
        protected:
        private:
            bool _isRunning;
            std::pair<int, int> _windowSize;
            sf::RenderWindow _window;
            sf::VideoMode _videoMode;

            void createWindow(int width, int height);
            void closeWindow(void);

            RayTracer::Scene _scene;
            std::shared_ptr<RayTracer::IRenderer> _renderer;
            std::shared_ptr<RayTracer::IDisplayer> _displayer;
            RayTracer::Frame _frame;
            bool _useFastRenderer;
    };
}
