/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IShape
*/

#pragma once

#include "Vector.hpp"
#include "Vertex.hpp"
#include "Ray.hpp"

namespace RayTracer {
    class IShape {
        public:
            Maths::Vector getNormal(const Maths::Vertex &vertex);
            bool hits(const Maths::Ray &ray) const;
    };
}