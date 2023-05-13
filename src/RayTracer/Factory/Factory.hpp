/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Factory
*/

#pragma once

#include <string>
#include "ILight.hpp"
#include "IShape.hpp"
#include <map>
#include <memory>
#include <functional>
#include "LoaderExceptions.hpp"
#include "type.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Cylinder.hpp"

namespace RayTracer
{
    // template <typename ObjectInterface>
    class Factory
    {
    public:
        Factory(void) = default;
        ~Factory() = default;

        std::shared_ptr<RayTracer::ILight> createLight(const std::string &name, libconfig::Setting &setting)
        {
            if (_lightMap.find(name) == _lightMap.end())
                throw LoaderException("Light not found");
            return _lightMap[name](setting);
        };
        std::shared_ptr<RayTracer::IShape> createShape(const std::string &name, libconfig::Setting &setting)
        {
            std::cerr << "create shape " << name << std::endl;
            if (_shapeMap.find(name) == _shapeMap.end())
                throw LoaderException("Shape not found");
            return _shapeMap[name](setting);
        }

    private:
        std::map<std::string, std::function<std::shared_ptr<RayTracer::IShape>(libconfig::Setting &)>> _shapeMap = {
            {"Sphere", [](libconfig::Setting &setting) { return std::make_shared<RayTracer::Sphere>(setting); }},
            {"Plane", [](libconfig::Setting &setting) { return std::make_shared<RayTracer::Plane>(setting); }},
            {"Cylinder", [](libconfig::Setting &setting) { return std::make_shared<RayTracer::Cylinder>(setting); }},
        };
        std::map<std::string, std::function<std::shared_ptr<RayTracer::ILight>(libconfig::Setting &)>> _lightMap = {};
    };

}
