/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** ILight
*/

#pragma once

#include <libconfig.h++>
#include "Vertex.hpp"
#include "Ray.hpp"
#include "Scene.hpp"
#include "HitRecord.hpp"

namespace RayTracer {
    class Scene;

    class ILight {
        public:
            virtual Maths::Vertex hit(const Maths::Ray &ray, const RayTracer::Scene &scene, const RayTracer::HitRecord &record) const = 0;
    };
}

