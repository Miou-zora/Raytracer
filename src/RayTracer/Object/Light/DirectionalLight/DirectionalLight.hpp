/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** DirectionalLight
*/

#pragma once

#include "Vertex.hpp"
#include "Vector.hpp"
#include "Light.hpp"

namespace RayTracer {
    class DirectionalLight : public RayTracer::Light {
        public:
            DirectionalLight(void);
            DirectionalLight(const Maths::Vertex &directionalLightColor, const float &directionalLightIntensity, const Maths::Vector &directionalLightDirection);
            ~DirectionalLight() = default;

            const Maths::Vertex &getDirectionalLightColor() const;
            void setDirectionalLightColor(const Maths::Vertex &directionalLightColor);
            const float &getDirectionalLightIntensity() const;
            void setDirectionalLightIntensity(float directionalLightIntensity);
            const Maths::Vector &getDirectionalLightDirection() const;
            void setDirectionalLightDirection(const Maths::Vector &directionalLightDirection);

            Maths::Vertex hit(const Maths::Vertex &position, const RayTracer::Scene &scene, const RayTracer::HitRecord &record) const;

        private:

            RayTracer::HitRecord castRay(const RayTracer::Scene &scene, const Maths::Ray &ray) const;
            RayTracer::HitRecord getClosestHit(const std::vector<RayTracer::HitRecord> &records) const;

            Maths::Vertex m_directionalLightColor;
            float m_directionalLightIntensity;
            Maths::Vector m_directionalLightDirection;
    };
}
