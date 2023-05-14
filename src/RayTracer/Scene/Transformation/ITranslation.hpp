/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ITranslation
*/

#pragma once

namespace RayTracer {
    class ITranslation {
        public:
            virtual void translate(double x, double y, double z) = 0;
            virtual void translateX(double x) = 0;
            virtual void translateY(double y) = 0;
            virtual void translateZ(double z) = 0;
    };
}
