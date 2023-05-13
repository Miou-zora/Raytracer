/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Cone
*/

#pragma once

#include "AShape.hpp"

namespace RayTracer {
    class Cone: public RayTracer::AShape {
        public:
            Cone(const Maths::Vertex &position, const double &angle, const double &height, const RayTracer::Material &material);
            ~Cone() = default;

            RayTracer::HitRecord hit(const Maths::Ray &ray) const;

            float getAngle() const { return _angle; };
            void setAngle(float radius) { _angle = radius; };
            float getHeight() const { return _height; };
            void setHeight(float height) { _height = height; };
        private:
            float _angle;
            float _height;
    };
};