/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** MathsUtils
*/

#pragma once

#include "Vector.hpp"
#include "Ray.hpp"
#include <cmath>

namespace Maths {
    /**
     * @brief A class that contains some useful maths functions
     */
    class MathsUtils {
        public:
            /**
             * @brief Get the Reflected Ray object
             *
             * @param normal
             * @param incident
             * @return Maths::Vector
             */
            static Maths::Vector GetReflectedRay(const Maths::Vector &normal,
                const Maths::Vector &incident)
            {
                return (((normal * incident) * normal) * 2 - incident);
            }

            /**
             * @brief Get the Reflected Ray object
             *
             * @param normal
             * @param incident
             * @return Maths::Ray
             */
            static Maths::Ray GetReflectedRay(const Maths::Vector &normal,
                const Maths::Ray &incident)
            {
                return (Maths::Ray(incident._origin,
                    GetReflectedRay(normal, incident._direction)));
            }
    };
}
