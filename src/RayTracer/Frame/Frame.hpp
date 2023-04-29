/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Frame
*/

#pragma once

#include "Vertex.hpp"
#include "RGBAColor.hpp"
#include <vector>

namespace RayTracer {
    class Frame {
        public:
            Frame(std::size_t width, std::size_t height): _width(width), _height(height) {};
            ~Frame() = default;

            void setPixel(const std::pair<int, int> &pos, const RayTracer::RGBAColor &color);

            const std::vector<std::vector<RayTracer::RGBAColor>> &getFrame(void) const;

        private:
            std::size_t _width;
            std::size_t _height;
            std::vector<std::vector<RayTracer::RGBAColor>> _frame; // 3D array of vertices (pixels)
    };
}
