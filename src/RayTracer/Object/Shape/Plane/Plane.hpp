/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Plane
*/

#pragma once
#include "AShape.hpp"

namespace RayTracer {
    class Plane : public RayTracer::AShape {
        public:
            Plane(void) = default;
            Plane(const Maths::Vertex &position);
            Plane(const Maths::Vertex &position, const RayTracer::Material &material);
            Plane(const Maths::Vertex &position, const Maths::Vertex &rotation,const RayTracer::Material &material);
            virtual ~Plane() = default;

            void loadConfig(libconfig::Setting &setting) override;

            RayTracer::HitRecord hit(const Maths::Ray &ray) const;

        private:
            Maths::Vector getNormal() const { return _normal; };
            void setNormal(const Maths::Vector &normal) { _normal = normal; };

            Maths::Vector _normal;
    };
}
