/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AShape
*/

#pragma once

#include "Object.hpp"
#include "IShape.hpp"
#include "Material.hpp"

namespace RayTracer {
    class AShape: public Object, public IShape {
        public:
            AShape();
            ~AShape();

            Material getMaterial() const { return _material; };
            void setMaterial(const Material &material) { _material = material; };

            bool isShadow() const { return _isShadow; };
            void setShadow(bool isShadow) { _isShadow = isShadow; };
        private:
            Material _material;
            bool _isShadow;
    };
};
