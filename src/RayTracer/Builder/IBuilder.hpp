/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** IBuilder
*/

#pragma once

#include "Scene.hpp"

namespace RayTracer {
    class IBuilder {
        public:
            virtual void build(RayTracer::Scene &scene) = 0;
    };
}
