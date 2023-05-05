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
            virtual void translate(float x, float y, float z) = 0;
            virtual void translateX(float x) = 0;
            virtual void translateY(float y) = 0;
            virtual void translateZ(float z) = 0;
    };
}
