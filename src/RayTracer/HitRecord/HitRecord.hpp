/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** HitRecord
*/

#pragma once

#include "Vertex.hpp"
#include "Vector.hpp"
#include "Material.hpp"
#include <memory>

namespace RayTracer {
    typedef struct {
        Maths::Vertex _intersection_point;
        Maths::Vector _normal;
        RayTracer::Material _material;
        bool _frontFace;
        bool _hit;
        float _distance;
    } HitRecord;
}
