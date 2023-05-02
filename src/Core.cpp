/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Core
*/

#include "Core.hpp"
#include <fstream>

void RayTracer::Core::run(void)
{
}

void RayTracer::Core::setScene(std::string scenePath)
{
    if (scenePath.empty())
        throw std::invalid_argument("Scene path is empty");
    std::ifstream file = std::ifstream(scenePath.c_str());
    if (file.fail())
        throw std::invalid_argument("Scene path is invalid");
    _scenePath = scenePath;
}

void RayTracer::Core::buildScene(void)
{

}

std::shared_ptr<RayTracer::AScene> RayTracer::Core::getScene(void) const
{
    return (nullptr);
}
