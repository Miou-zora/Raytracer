/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Core
*/

#pragma once

#include <memory>
#include "AScene.hpp"
#include "IRenderer.hpp"
#include "IDisplayer.hpp"

namespace RayTracer {
    class Core {
        public:
            Core(void) = default;
            virtual ~Core() = default;

            void buildScene(void);
            void run(void);
            void setScene(std::string scenePath);
            std::shared_ptr<RayTracer::AScene> getScene(void) const;
        private:
            std::string _scenePath;
            std::shared_ptr<RayTracer::AScene> _scene;
            std::shared_ptr<RayTracer::IRenderer> _renderer;
            std::shared_ptr<RayTracer::IDisplayer> _displayer;
    };
}
