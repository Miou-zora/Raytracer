/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ICamera
*/

#pragma once

#include "Ray.hpp"

namespace RayTracer {
    class ICamera {
        public:
            virtual Maths::Ray ray(double u, double v) const = 0;
    };
};
