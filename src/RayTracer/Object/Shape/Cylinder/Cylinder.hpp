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
            Cylinder(void) = default;
            Cylinder(const Maths::Vertex &center, double radius, double height);
            Cylinder(const Maths::Vertex &center, double radius, double height, const RayTracer::Material &material);
            virtual ~Cylinder() = default;
            void loadConfig(libconfig::Setting &setting) override;
            RayTracer::HitRecord hit(const Maths::Ray &ray) const;

        private:
            double _radius;
            double _height;
    };
}
