/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Factory
*/

#include "Factory.hpp"
#include "ErrorHandling.hpp"

RayTracer::Factory::Factory(void)
{
}

RayTracer::Factory::~Factory()
{
}

std::shared_ptr<RayTracer::IShape> RayTracer::Factory::createShape(const std::string &name)
{
    auto it = _shapeMap.find(name);
    if (it == _shapeMap.end())
        throw RayTracer::InvalidShapeException("Invalid shape name");
    std::shared_ptr<RayTracer::IShape> shape = it->second(name);
    return (shape);
}

std::shared_ptr<RayTracer::ILight> RayTracer::Factory::createLight(const std::string &name)
{
    auto it = _lightMap.find(name);
    if (it == _lightMap.end())
        throw RayTracer::InvalidLightException("Invalid light name");
    std::shared_ptr<RayTracer::ILight> light = it->second(name);
    return (light);
}