/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Material
*/

#pragma once

#include "Vector.hpp"
#include "RGBAColor.hpp"

namespace RayTracer {
    class Material {
        public:
            Material(void): _emissionColor(Maths::Vertex(0, 0, 0)), _emissionStrength(0), _color(Maths::Vertex(1, 1, 1)) {};
            ~Material() = default;

            const Maths::Vertex &getColor() const { return _color; };
            const Maths::Vertex &getEmissionColor() const { return _emissionColor; };
            double getEmissionStrength() const { return _emissionStrength; };

            void setColor(const Maths::Vertex &color) { _color = color; };
            void setEmissionColor(const Maths::Vertex &color) { _emissionColor = color; };
            void setEmissionStrength(double strength) { _emissionStrength = strength; };

            bool operator==(const Material &other) const {
                return _color == other.getColor() &&
                    _emissionColor == other.getEmissionColor() &&
                    _emissionStrength == other.getEmissionStrength();
            }

            bool operator!=(const Material &other) const {
                return !(*this == other);
            }

            static RayTracer::Material flatColor(Maths::Vertex color) {
                RayTracer::Material material;

                material.setColor(color);
                material.setEmissionColor(Maths::Vertex(0, 0, 0));
                material.setEmissionStrength(0);
                return material;
            }
        protected:
        private:
            Maths::Vertex _emissionColor;
            double _emissionStrength;
            Maths::Vertex _color;
    };
};
