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

            void setPixel(const std::pair<std::size_t, std::size_t> &pos, const RayTracer::RGBAColor &color);

            const std::vector<std::vector<RayTracer::RGBAColor>> &getRect(void) const;

            std::size_t getWidth(void) const { return _width; };
            std::size_t getHeight(void) const { return _height; };
        private:
            std::size_t _width;
            std::size_t _height;
            std::vector<std::vector<RayTracer::RGBAColor>> _rect; // 2D array of vertices (pixels)
    };
}
