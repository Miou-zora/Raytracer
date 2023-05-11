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
    for (std::size_t i = frame.getHeight(); i > 0; i--) {
        for (std::size_t j = 0; j < frame.getWidth(); j++) {
            RayTracer::RGBAColor pixel = frame.getPixel(std::make_pair(j, i - 1));
            if (pixel.getRed() > 255)
                pixel.setRed(255);
            if (pixel.getGreen() > 255)
                pixel.setGreen(255);
            if (pixel.getBlue() > 255)
                pixel.setBlue(255);
            std::cout << static_cast<int>(pixel.getRed()) << " ";
            std::cout << static_cast<int>(pixel.getGreen()) << " ";
            std::cout << static_cast<int>(pixel.getBlue()) << std::endl;
        }
    }
}
