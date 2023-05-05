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
            virtual void rotate(float x, float y, float z) = 0;
            virtual void rotateX(float x) = 0;
            virtual void rotateY(float y) = 0;
            virtual void rotateZ(float z) = 0;
    };
};
