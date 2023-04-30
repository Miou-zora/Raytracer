/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** IBuilder
*/

#pragma once

#include "AScene.hpp"
#include <string>

namespace RayTracer {
    class IBuilder {
        public:
            virtual void build(const RayTracer::AScene &scene, std::string scenePath) = 0;
    };
}
