/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** IRotation
*/

#pragma once

namespace RayTracer {
    class IRotation {
        public:
            virtual void rotate(double x, double y, double z) = 0;
            virtual void rotateX(double x) = 0;
            virtual void rotateY(double y) = 0;
            virtual void rotateZ(double z) = 0;
    };
};
