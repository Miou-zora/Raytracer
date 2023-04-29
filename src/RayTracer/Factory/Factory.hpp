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
#include <memory>

namespace RayTracer {
    class Factory {
        public:
            Factory(void);
            ~Factory();

            std::shared_ptr<RayTracer::ILight> createLight(std::string name);
            std::shared_ptr<RayTracer::IShape> createShape(std::string name);

        protected:
        private:
    };
}
