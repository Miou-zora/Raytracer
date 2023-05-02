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

            static double distance(const Maths::Vertex &lhs, const Maths::Vertex &rhs)
            {
                return (std::sqrt(std::pow(rhs._x - lhs._x, 2) +
                    std::pow(rhs._y - lhs._y, 2) +
                    std::pow(rhs._z - lhs._z, 2)));
            }
    };
}

inline Maths::Vertex operator+(const Maths::Vertex &lhs, const Maths::Vector &rhs)
{
    return (Maths::Vertex(lhs._x + rhs._x, lhs._y + rhs._y, lhs._z + rhs._z));
}

inline Maths::Vector VertexToVector(const Maths::Vertex &lhs)
{
    return (Maths::Vector(lhs._x, lhs._y, lhs._z));
}

inline Maths::Vertex VectorToVertex(const Maths::Vector &lhs)
{
    return (Maths::Vertex(lhs._x, lhs._y, lhs._z));
}
