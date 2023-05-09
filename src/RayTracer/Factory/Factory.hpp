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
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Cylindre.hpp"

namespace RayTracer {
    class Factory {
        public:
            Factory(void);
            ~Factory();

            std::shared_ptr<RayTracer::ILight> createLight(const std::string &name);
            std::shared_ptr<RayTracer::IShape> createShape(const std::string &name);

        protected:
        private:
            std::map<std::string, std::function<std::shared_ptr<RayTracer::IShape>(const std::string&)>> _shapeMap = {
               {"Sphere", [](const std::string& name){ return std::make_shared<RayTracer::Sphere>(name);}},
               {"Plane", [](const std::string& name){ return std::make_shared<RayTracer::Plane>(name);}},
               {"Cylindre", [](const std::string& name){ return std::make_shared<RayTracer::Cylindre>(name);}},
            };
            std::map<std::string, std::function<std::shared_ptr<RayTracer::ILight>(const std::string&)>> _lightMap = {
            };
    };
}
