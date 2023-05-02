/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Camera
*/

#pragma once

#include "Object.hpp"
#include "Rect3D.hpp"
#include "ICamera.hpp"

namespace RayTracer {
    class Camera: public Object, public ICamera {
        public:
            Camera(int width, int height, double fov);
            virtual ~Camera() = default;
            Maths::Rect3D getScreen() const { return _screen; };
            void setScreen(Maths::Rect3D screen) { _screen = screen; };

            Maths::Ray ray(double u, double v) const override;
        private:
            Maths::Rect3D _screen;
    };
};
