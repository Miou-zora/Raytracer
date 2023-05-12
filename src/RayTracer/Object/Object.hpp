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

#include <libconfig.h++>
#include <cstddef>

namespace RayTracer {
    class AObject: public RayTracer::ITranslation, public RayTracer::IRotation {
        public:
            AObject(void): _position(Maths::Vertex(0, 0, 0)), _rotation(Maths::Vertex(0, 0, 0)) {};
            virtual ~AObject() = default;
            virtual void loadConfig(libconfig::Setting &setting) = 0;

            Maths::Vertex getPosition(void) const { return _position; };
            Maths::Vertex getRotation(void) const { return _rotation; };
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
