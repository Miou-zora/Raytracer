/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Lights
*/

#pragma once

#include "AObject.hpp"
#include "ILights.hpp"

namespace RayTracer {
    class Lights: public ILights, public AObject {
        public:
            Lights();
            ~Lights();
    };
};
