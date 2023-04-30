/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** IRenderer
*/

#pragma once

#include "AScene.hpp"
#include "Frame.hpp"

namespace RayTracer {
    /// @brief IRenderer class that will render the scene
    class IRenderer {
        public:
            /// @brief Render the scene and put it in frame
            virtual void render(const RayTracer::AScene &scene, RayTracer::Frame &frame) = 0;
    };
}
