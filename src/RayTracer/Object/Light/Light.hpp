/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Light
*/

#pragma once

#include "Object.hpp"
#include "ILight.hpp"

namespace RayTracer {
    class Light: public ILight, public Object {
        public:
            Light(void) = default;
            ~Light() = default;
    };
};
