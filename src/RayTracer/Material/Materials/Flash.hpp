/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Materials Flash
*/

#pragma once

#include "Vector.hpp"
#include "RGBAColor.hpp"
#include "Material.hpp"

namespace RayTracer {
    class Flash {
        static RayTracer::Material FlashColor(Maths::Vertex color) {
            RayTracer::Material material;

            material.setColor(color);
            material.setEmissionColor(Maths::Vertex(0, 0, 1));
            material.setEmissionStrength(0);
            material.setSmoothness(0);

            return material;
        }
    }
}
