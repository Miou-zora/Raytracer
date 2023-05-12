/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** IBuilder
*/

#pragma once

#include "Scene.hpp"
#include "Factory.hpp"

namespace RayTracer {
    class IBuilder {
        public:
            virtual void buildLightFactory(void) = 0;
            virtual void buildShapeFactory(void) = 0;
            virtual void buildScene(std::string sceneFilepath, RayTracer::Scene &scene) = 0;
    };
}
