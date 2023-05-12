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
            SFMLCore(int width, int height);
            ~SFMLCore();

            void init(void);

            void run(void);

            void buildScene(void);
            void setScene(std::string scenePath);
            std::shared_ptr<RayTracer::Scene> getScene(void) const;
        protected:
        private:
            bool _isRunning;
            std::pair<int, int> _windowSize;
            sf::RenderWindow _window;
            sf::VideoMode _videoMode;

            void createWindow(void);
            void closeWindow(void);

            std::string _scenePath;
            std::shared_ptr<RayTracer::Scene> _scene;
            std::shared_ptr<RayTracer::IRenderer> _renderer;
            std::shared_ptr<RayTracer::IDisplayer> _displayer;
    };
}
