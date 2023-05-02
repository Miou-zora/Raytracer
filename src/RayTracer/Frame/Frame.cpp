/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Frame
*/

#include "Frame.hpp"

void RayTracer::Frame::setPixel(const std::pair<std::size_t, std::size_t> &pos, const RayTracer::RGBAColor &color)
{
    _rect[pos.first][pos.second] = color;
}
