/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** MathsUtils
*/

#pragma once

#include "Vector.hpp"
#include <cmath>

namespace Maths {
    class MathsUtils {
        public:
            static Maths::Vector GetReflectedRay(const Maths::Vector &normal,
                const Maths::Vector &incident)
            {
                return (((normal * incident) * normal) * 2 - incident);
            }
    };
}
