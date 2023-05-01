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
#include "HitRecord.hpp"

namespace RayTracer {
    class IShape {
        public:
            virtual RayTracer::HitRecord hit(const Maths::Ray &ray) const = 0;
    };
}
