/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** EnhanceRenderer
*/

#pragma once

#include "IRenderer.hpp"

namespace RayTracer {
    class EnhanceRenderer : virtual public IRenderer{
        public:
            EnhanceRenderer(const std::vector<std::shared_ptr<IShape>> &shapes) : m_shapes(shapes), m_ambientColor(Maths::Vertex(0.25, 0.25, 0.35)) { };
            ~EnhanceRenderer() = default;

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
