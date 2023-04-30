/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Object
*/

#pragma once

#include "ITranslation.hpp"
#include "IRotation.hpp"
#include "Vertex.hpp"

#include <cstddef>

namespace RayTracer {
    class Object: public RayTracer::ITranslation, public RayTracer::IRotation {
        public:
            Maths::Vertex &getPosition(void) { return _position; };
            Maths::Vertex &getRotation(void) { return _rotation; };
            void setPosition(const Maths::Vertex &position) { _position = position; };
            void setRotation(const Maths::Vertex &rotation) { _rotation = rotation; };

            void translate(double x, double y, double z);
            void translateX(double x);
            void translateY(double y);
            void translateZ(double z);

            void rotate(double x, double y, double z);
            void rotateX(double x);
            void rotateY(double y);
            void rotateZ(double z);
        private:
            Maths::Vertex _position;
            Maths::Vertex _rotation;
    };
};
