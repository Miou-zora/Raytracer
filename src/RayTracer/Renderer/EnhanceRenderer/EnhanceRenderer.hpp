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
            EnhanceRenderer(void) :
                m_ambientColor(Maths::Vertex(0.25, 0.25, 0.35)),
                m_directionalLightColor(Maths::Vertex(1, 1, 1)),
                m_directionalLightDirection(Maths::Vector(0, 0, -1)) { };
            ~EnhanceRenderer() = default;

            void render(const RayTracer::Scene &scene, RayTracer::Frame &frame);
            RayTracer::RGBAColor cast(const RayTracer::Scene &scene, const Maths::Ray &ray);
        protected:
        private:
            Maths::Vertex trace(const RayTracer::Scene &scene, const Maths::Ray &ray);
            RayTracer::HitRecord castRay(const Scene &scene, const Maths::Ray &ray) const;
            RayTracer::HitRecord getClosestHit(const std::vector<RayTracer::HitRecord> &records) const;
            const Maths::Vertex m_ambientColor;
            const Maths::Vertex m_directionalLightColor;
            const Maths::Vector m_directionalLightDirection;
            const double m_ambientIntensity = 1;
            const double m_directionalLightIntensity = 0.5;
            const double m_directionalFocus = 0.8;
    };
}

constexpr std::size_t MAX_DEPTH = 10;
constexpr std::size_t RAY_PER_PIXEL = 10;
