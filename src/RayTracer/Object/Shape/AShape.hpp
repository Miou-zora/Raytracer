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
    class AShape: public RayTracer::AObject, public RayTracer::IShape {
        public:
            AShape(void): RayTracer::AObject(), _material(RayTracer::Material()), _isShadow(true) {};
            virtual ~AShape() = default;

            RayTracer::Material getMaterial() const { return _material; };
            void setMaterial(const Material &material) { _material = material; };

            bool isShadow() const { return _isShadow; };
            void setShadow(bool isShadow) { _isShadow = isShadow; };
        private:
            RayTracer::Material _material;
            bool _isShadow;
    };
};
