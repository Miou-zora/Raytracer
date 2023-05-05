/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Factory
*/

#include "Factory.hpp"

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
        return nullptr;
    std::shared_ptr<RayTracer::IShape> shape = it->second(name);
    return (shape);
}

std::shared_ptr<RayTracer::ILight> RayTracer::Factory::createLight(const std::string &name)
{
    auto it = _lightMap.find(name);
    if (it == _lightMap.end())
        return nullptr;
    std::shared_ptr<RayTracer::ILight> light = it->second(name);
    return (light);
}
