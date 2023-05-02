/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Renderer
*/

#include "Renderer.hpp"
#include "ICamera.hpp"

RayTracer::Renderer::Renderer(void)
{
}

RayTracer::Renderer::~Renderer()
{
}

RayTracer::RGBAColor RayTracer::Renderer::castRay(const RayTracer::AScene &scene, const Maths::Ray &ray) const
{
    for (auto &shape : scene.getShapes()) {
        RayTracer::HitRecord record = shape.get()->hit(ray);
        if (record.isHit() && record.isFrontFace()) {
            return record.getColor();
        }
    }
    return RayTracer::RGBAColor(0, 0, 0, 255);
}

void RayTracer::Renderer::render(const RayTracer::AScene &scene, RayTracer::Frame &frame)
{
    RayTracer::ICamera camera = scene.getCamera().get();

    for (std::size_t i = 0; i < frame.getWidth(); i++) {
        for (std::size_t j = 0; j < frame.getHeight(); j++) {
            double x = i / (double)frame.getWidth();
            double y = j / (double)frame.getHeight();
            Maths::Ray ray = camera.ray(x, y);
            frame.setPixel(i, j, this->castRay(scene, ray));
        }
    }
}