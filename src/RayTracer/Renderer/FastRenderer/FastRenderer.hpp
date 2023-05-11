/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** FastRenderer
*/

#pragma once
#include "IRenderer.hpp"

namespace RayTracer {
    class FastRenderer : virtual public RayTracer::IRenderer{
        public:
            FastRenderer(void);
            ~FastRenderer();

            void render(const RayTracer::Scene &scene, RayTracer::Frame &frame);

        private:
            RayTracer::HitRecord castRay(const Scene &scene, const Maths::Ray &ray) const;
            RayTracer::HitRecord getClosestHit(const std::vector<RayTracer::HitRecord> &records) const;
            Maths::Vertex findDirectionalLightCoeff(const RayTracer::Scene &scene, const RayTracer::HitRecord &record, const Maths::Ray &ray) const;
            RayTracer::RGBAColor cast(const RayTracer::Scene &scene, const Maths::Ray &ray) const;
            const Maths::Vertex m_ambientLightColor;
            const float m_ambientLightIntensity;
    };
}
