/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** IRenderer
*/

#pragma once

#include "Scene.hpp"
#include "Frame.hpp"

namespace RayTracer {
    /// @brief IRenderer class that will render the scene
    class IRenderer {
        public:
            /// @brief Render the scene and put it in frame
            virtual void render(const RayTracer::Scene &scene, RayTracer::Frame &frame) = 0;
    };
}
