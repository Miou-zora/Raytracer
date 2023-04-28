/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Lights
*/

#pragma once

#include "Object.hpp"
#include "ILights.hpp"

namespace RayTracer {
    class Lights: public ILights, public Object {
        public:
            Lights();
            ~Lights();
    };
};
