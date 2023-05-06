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
            Renderer(const std::vector<std::shared_ptr<IShape>> &shapes) : m_shapes(shapes), m_ambientColor(Maths::Vertex(0.25, 0.25, 0.35)) { };
            ~Renderer() = default;

            void render(const RayTracer::Scene &scene, RayTracer::Frame &frame);
            RayTracer::RGBAColor cast(const RayTracer::Scene &scene, const Maths::Ray &ray);
        protected:
        private:
            Maths::Vertex trace(const RayTracer::Scene &scene, const Maths::Ray &ray);
            RayTracer::HitRecord castRay(const Scene &scene, const Maths::Ray &ray) const;
            RayTracer::HitRecord getClosestHit(const std::vector<RayTracer::HitRecord> &records) const;
            const std::vector<std::shared_ptr<IShape>> m_shapes;
            const Maths::Vertex m_ambientColor;
    };
}

    constexpr std::size_t MAX_DEPTH = 10;
    constexpr std::size_t RAY_PER_PIXEL = 10;
