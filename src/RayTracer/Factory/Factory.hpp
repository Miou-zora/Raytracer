/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Factory
*/

#pragma once

#include <string>
#include "ILight.hpp"
#include "IObject.hpp"
#include "IDisplayer.hpp"
#include <memory>

namespace RayTracer {
    class Factory {
        public:
            Factory();
            ~Factory();

            std::shared_ptr<RayTracer::ILight> createLight(std::string name);
            std::shared_ptr<RayTracer::IObject> createObject(std::string name);
            std::shared_ptr<RayTracer::IDisplayer> createDisplayer(std::string name);

        protected:
        private:
    };
}
