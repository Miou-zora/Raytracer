/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AShape
*/

#pragma once

#include "AObject.hpp"
#include "IShape.hpp"

namespace RayTracer {
    class AShape: public AObject, public IShape {
        public:
            AShape();
            ~AShape();
    };
};
