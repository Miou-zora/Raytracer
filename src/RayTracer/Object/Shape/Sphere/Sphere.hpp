/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Sphere
*/

#pragma once
#include "AShape.hpp"

namespace RayTracer {
    class Sphere : public RayTracer::AShape {
        public:
            Sphere(void) = default;
            Sphere(const Maths::Vertex &center, double radius);
            Sphere(const Maths::Vertex &center, double radius, const RayTracer::Material &material);
            virtual ~Sphere() = default;

            RayTracer::HitRecord hit(const Maths::Ray &ray) const;

            double getRadius() const { return _radius; };
            void setRadius(double radius) { _radius = radius; };

        private:
            double _radius;
    };
}
