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
            virtual void buildScene(RayTracer::Scene &scene) = 0;
    };
}
