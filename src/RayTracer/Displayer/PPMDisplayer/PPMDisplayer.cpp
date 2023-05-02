/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** PPMDisplayer
*/

#include "PPMDisplayer.hpp"

void RayTracer::PPMDisplayer::display(const RayTracer::Frame &frame)
{
    std::cout << "P3" << std::endl;
    std::cout << frame.getWidth() << " " << frame.getHeight() << std::endl;
    std::cout << "255" << std::endl;
    for (std::size_t i = 0; i < frame.getHeight(); i++) {
        for (std::size_t j = 0; j < frame.getWidth(); j++) {
            RayTracer::RGBAColor pixel = frame.getPixel(std::make_pair(i, j));
            std::cout << pixel.getRed() << " " << pixel.getGreen() << " " << pixel.getBlue() << std::endl;
        }
    }
}
