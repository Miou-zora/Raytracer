/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** IRenderer
*/

#pragma once

#include "AScene.hpp"

namespace RayTracer {
    /// @brief IRenderer class that will render the scene
    class IRenderer {
        public:
            virtual void render(const RayTracer::AScene &scene) = 0;
    };
}
