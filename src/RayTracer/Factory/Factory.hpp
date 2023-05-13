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

namespace RayTracer {
    // template <typename ObjectInterface>
        class Factory {
            public:
            Factory(void) = default;
            ~Factory() = default;

            std::shared_ptr<RayTracer::ILight> createLight(const std::string &name) {
                if (_lightMap.find(name) == _lightMap.end())
                    throw LoaderException("Light not found");
                return _lightMap[name]();
            };
            std::shared_ptr<RayTracer::IShape> createShape(const std::string &name) {
                std::cerr << "create shape " << name << std::endl;
                if (_shapeMap.find(name) == _shapeMap.end())
                    throw LoaderException("Shape not found");
                return _shapeMap[name]();
            }
        protected:
        private:
            std::map<std::string, std::function<std::shared_ptr<RayTracer::IShape>()>> _shapeMap = {
               {"Sphere", [](){ return std::make_shared<RayTracer::Sphere>();}},
               {"Plane", [](){ return std::make_shared<RayTracer::Plane>();}},
               {"Cylinder", [](){ return std::make_shared<RayTracer::Cylinder>();}},
            };
            std::map<std::string, std::function<std::shared_ptr<RayTracer::ILight>()>> _lightMap = {
            };
        };
}

