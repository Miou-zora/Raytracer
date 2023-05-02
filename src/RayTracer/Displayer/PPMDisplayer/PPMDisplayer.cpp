/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** PPMDisplayer
*/

#include "PPMDisplayer.hpp"

void RayTracer::PPMDisplayer::display(const RayTracer::Frame &frame)
{
    std::vector<std::vector<RayTracer::RGBAColor>> rect = frame.getRect();

    std::cout << "P3" << std::endl;
    std::cout << frame.getWidth() << " " << frame.getHeight() << std::endl;
    std::cout << "255" << std::endl;
    for (std::size_t i = 0; i < frame.getHeight(); i++) {
        for (std::size_t j = 0; j < frame.getWidth(); j++) {
            std::cout << rect[i][j].getRed() << " " << rect[i][j].getGreen() << " " << rect[i][j].getBlue() << std::endl;
        }
    }
}
