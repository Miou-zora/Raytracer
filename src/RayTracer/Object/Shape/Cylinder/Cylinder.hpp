/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Cylinder
*/

#pragma once
#include "AShape.hpp"

namespace RayTracer {
    class Cylinder : public RayTracer::AShape {
        public:
            Cylinder(void);
            Cylinder(const Maths::Vertex &position);
            Cylinder(const Maths::Vertex &position, const RayTracer::Material &material);
            Cylinder(const Maths::Vertex &position, const Maths::Vertex &rotation, const RayTracer::Material &material);
            virtual ~Cylinder() = default;
            RayTracer::HitRecord hit(const Maths::Ray &ray) const;
        private:
            Maths::Vector getNormal() const { return _normal; };
            void setNormal(const Maths::Vector &normal) { _normal = normal; };
            Maths::Vector _normal;
    };
}
