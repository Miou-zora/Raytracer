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
            Material(void): _emissionColor(Maths::Vertex(0, 0, 0)), _emissionStrength(0), _color(RayTracer::RGBAColor(255, 255, 255)) {};
            ~Material() = default;

            RayTracer::RGBAColor getColor() const { return _color; };
            Maths::Vertex getEmissionColor() const { return _emissionColor; };
            float getEmissionStrength() const { return _emissionStrength; };

            void setColor(const RayTracer::RGBAColor &color) { _color = color; };
            void setEmissionColor(const Maths::Vertex &color) { _emissionColor = color; };
            void setEmissionStrength(float strength) { _emissionStrength = strength; };

            bool operator==(const Material &other) const {
                return _color == other.getColor() &&
                    _emissionColor == other.getEmissionColor() &&
                    _emissionStrength == other.getEmissionStrength();
            }

            bool operator!=(const Material &other) const {
                return !(*this == other);
            }
        protected:
        private:
            Maths::Vertex _emissionColor;
            float _emissionStrength;
            RayTracer::RGBAColor _color;
    };
};
