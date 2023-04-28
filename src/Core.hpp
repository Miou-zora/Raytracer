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

namespace RayTracer {
    class Core {
        public:
            Core(void) = default;
            virtual ~Core() = default;

            void buildScene(void);
            void run(void);
            void setScene(std::string scenePath);
            std::shared_ptr<AScene> getScene(void) const;
        private:
            std::string _scenePath;
            std::shared_ptr<AScene> _scene;
            std::shared_ptr<IRenderer> _renderer;
    };
}
