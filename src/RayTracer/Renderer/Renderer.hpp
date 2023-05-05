/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Renderer
*/

#pragma once

#include "IRenderer.hpp"

namespace RayTracer {
    class Renderer : virtual public IRenderer{
        public:
            Renderer(void) = default;
            ~Renderer() = default;

            void render(const RayTracer::Scene &scene, RayTracer::Frame &frame);
        protected:
        private:
            Maths::Vertex trace(const RayTracer::Scene &scene, const Maths::Ray &ray);
            RayTracer::HitRecord castRay(const Scene &scene, const Maths::Ray &ray) const;
            RayTracer::HitRecord getClosestHit(const std::vector<RayTracer::HitRecord> &records) const;
            RayTracer::RGBAColor cast(const RayTracer::Scene &scene, const Maths::Ray &ray);
    };
}

    constexpr std::size_t MAX_DEPTH = 20;
    constexpr std::size_t RAY_PER_PIXEL = 20;
