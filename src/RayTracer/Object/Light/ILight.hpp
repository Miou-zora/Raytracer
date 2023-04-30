/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** ILight
*/

#pragma once

#include "Vertex.hpp"

namespace RayTracer {
    class ILight {
        public:
            bool hits(const Maths::Vertex &vertex) const;
    };
}

