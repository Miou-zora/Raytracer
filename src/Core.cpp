/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Core
*/

#include "Core.hpp"

void RayTracer::Core::run(void)
{

}

void RayTracer::Core::build(std::string scenePath)
{
    RayTracer::Builder builder;

    try {
        builder.setScenePath(scenePath);
        builder.buildScene(_scene);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        throw std::invalid_argument("Error while loading scene");
    }
}
