/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Materials mirror
*/

#pragma once

#include "Material.hpp"

namespace RayTracer {
    namespace Materials {
        static RayTracer::Material MirrorColor(Maths::Vertex color) {
            RayTracer::Material material;

            material.setColor(color);
            material.setEmissionColor(Maths::Vertex(0, 0, 0));
            material.setEmissionStrength(0);
            material.setSmoothness(1);

            return material;
        }
    }
}
