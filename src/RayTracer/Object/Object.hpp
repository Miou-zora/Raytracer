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
            Object(void): _position(Maths::Vertex(0, 0, 0)), _rotation(Maths::Vertex(0, 0, 0)) {};
            virtual ~Object() = default;
            Maths::Vertex getPosition(void) const { return _position; };
            Maths::Vertex getRotation(void) const { return _rotation; };
            void setPosition(const Maths::Vertex &position) { _position = position; };
            void setRotation(const Maths::Vertex &rotation) { _rotation = rotation; };

            void translate(float x, float y, float z);
            void translateX(float x);
            void translateY(float y);
            void translateZ(float z);

            void rotate(float x, float y, float z);
            void rotateX(float x);
            void rotateY(float y);
            void rotateZ(float z);
        private:
            Maths::Vertex _position;
            Maths::Vertex _rotation;
    };
};
