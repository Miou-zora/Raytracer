/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Cylinder
*/

#pragma once
#include "AShape.hpp"
#include "Material.hpp"

namespace RayTracer {
    class Cylinder : public RayTracer::AShape {
        public:
            Cylinder(void) = default;
            Cylinder(libconfig::Setting &setting);
            Cylinder(const Maths::Vertex &center, double radius);
            Cylinder(const Maths::Vertex &center, double radius, const RayTracer::Material &material);
            virtual ~Cylinder() = default;
            RayTracer::HitRecord hit(const Maths::Ray &ray) const;

        private:
            double _radius;
    };
}
