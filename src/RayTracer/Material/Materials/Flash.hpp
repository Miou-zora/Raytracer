/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Materials Flash
*/

#pragma once

#include "Material.hpp"

namespace RayTracer {
    namespace Materials {
        static RayTracer::Material FlashColor(Maths::Vertex color, float strength) {
            RayTracer::Material material;

            material.setColor(color);
            material.setEmissionColor(Maths::Vertex(1, 1, 1));
            material.setEmissionStrength(strength);
            material.setSmoothness(0);

            return material;
        }
    }
}
