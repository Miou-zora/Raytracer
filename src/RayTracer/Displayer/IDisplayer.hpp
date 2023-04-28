/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** IDisplayer
*/

#pragma once

#include "Frame.hpp"

namespace RayTracer {
    class IDisplayer {
        public:
            virtual void display(const RayTracer::Frame &frame) = 0;
    };
}
