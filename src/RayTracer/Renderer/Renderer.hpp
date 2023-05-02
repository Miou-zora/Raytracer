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
            Renderer(void);
            ~Renderer();

            void render(const RayTracer::AScene &scene, RayTracer::Frame &frame);

        protected:
        private:
            RGBAColor castRay(const AScene &scene, const Maths::Ray &ray) const;
            RayTracer::HitRecord getClosestHit(const std::vector<RayTracer::HitRecord> &records) const;
    };
}
