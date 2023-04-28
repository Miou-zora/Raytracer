/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Frame
*/

#pragma once

#include "Vertex.hpp"
#include "IColor.hpp"
#include <vector>

namespace RayTracer {
    class Frame {
        public:
            Frame() = default;
            ~Frame() = default;

            void setPixel(const Maths::Vertex &vertex, const RayTracer::IColor &color);

        private:
            std::vector<std::vector<Maths::Vertex>> _frame; // 3D array of vertices (pixels)
    };
}
