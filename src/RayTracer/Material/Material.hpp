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
            Material(void): _ambient(0.1), _diffuse(0.9), _specular(0.9), _reflective(0.0), _color(RayTracer::RGBAColor(255, 255, 255)) {};
            ~Material() = default;

            double getAmbient() const { return _ambient; };
            double getDiffuse() const { return _diffuse; };
            double getSpecular() const { return _specular; };
            double getReflective() const { return _reflective; };
            RayTracer::RGBAColor getColor() const { return _color; };

            void setAmbient(double ambient) { _ambient = ambient; };
            void setDiffuse(double diffuse) { _diffuse = diffuse; };
            void setSpecular(double specular) { _specular = specular; };
            void setReflective(double reflective) { _reflective = reflective; };
            void setColor(const RayTracer::RGBAColor &color) { _color = color; };

            bool operator==(const Material &other) const {
                return _ambient == other.getAmbient() &&
                    _diffuse == other.getDiffuse() &&
                    _specular == other.getSpecular() &&
                    _reflective == other.getReflective() &&
                    _color == other.getColor();
            }

            bool operator!=(const Material &other) const {
                return !(*this == other);
            }
        protected:
        private:
            double _ambient;
            double _diffuse;
            double _specular;
            double _reflective;
            RayTracer::RGBAColor _color;
    };
};
