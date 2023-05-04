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
            Material(void) = default;
            ~Material() = default;

            RayTracer::RGBAColor getColor() const { return _color; };
            Maths::Vertex getEmissionColor() const { return emissionColor; };
            double getEmissionStrength() const { return emissionStrength; };

            void setColor(const RayTracer::RGBAColor &color) { _color = color; };
            void setEmissionColor(const Maths::Vertex &color) { emissionColor = color; };
            void setEmissionStrength(double strength) { emissionStrength = strength; };

            bool operator==(const Material &other) const {
                return _color == other.getColor() &&
                    emissionColor == other.getEmissionColor() &&
                    emissionStrength == other.getEmissionStrength();
            }

            bool operator!=(const Material &other) const {
                return !(*this == other);
            }
        protected:
        private:
            Maths::Vertex emissionColor;
            double emissionStrength;
            RayTracer::RGBAColor _color;
    };
};
