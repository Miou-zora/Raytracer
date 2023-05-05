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
            Sphere(const Maths::Vertex &center, float radius);
            Sphere(const Maths::Vertex &center, float radius, const RayTracer::Material &material);
            virtual ~Sphere() = default;

            RayTracer::HitRecord hit(const Maths::Ray &ray) const;

            float getRadius() const { return _radius; };
            void setRadius(float radius) { _radius = radius; };

        private:
            float _radius;
    };
}
