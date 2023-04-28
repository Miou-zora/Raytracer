/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** ILights
*/

#pragma once

#include "Vertex.hpp"

namespace RayTracer {
    class ILights {
        public:
            bool hits(const Maths::Vertex &vertex) const;
    };
}

