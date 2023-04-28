/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Material
*/

#pragma once

#include "Vector.hpp"

namespace RayTracer {
    class Material {
        public:
            Material();
            ~Material();

            double getAmbient() const { return _ambient; };
            double getDiffuse() const { return _diffuse; };
            double getSpecular() const { return _specular; };
            double getReflective() const { return _reflective; };
            Maths::Vector getColor() const { return _color; };

            void setAmbient(double ambient) { _ambient = ambient; };
            void setDiffuse(double diffuse) { _diffuse = diffuse; };
            void setSpecular(double specular) { _specular = specular; };
            void setReflective(double reflective) { _reflective = reflective; };
            void setColor(const Maths::Vector &color) { _color = color; };
        protected:
        private:
            double _ambient;
            double _diffuse;
            double _specular;
            double _reflective;
            Maths::Vector _color;
    };
};
