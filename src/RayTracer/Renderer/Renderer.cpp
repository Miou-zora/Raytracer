/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Renderer
*/

#include "Renderer.hpp"
#include "ICamera.hpp"
#include "MathsUtils.hpp"

RayTracer::HitRecord RayTracer::Renderer::castRay(const RayTracer::Scene &scene, const Maths::Ray &ray) const
{
    float distance = -1;
    RayTracer::HitRecord closestHit;
    RayTracer::HitRecord record;

    for (const std::shared_ptr<RayTracer::IShape> &shape : scene.getShapes()) {
        record = shape->hit(ray);
        if (record._hit && (record._distance < distance || distance == -1)) {
            distance = record._distance;
            closestHit = record;
        }
    }
    if (distance <= 0) {
        closestHit._hit = false;
    }
    return closestHit;
}

Maths::Vertex RayTracer::Renderer::trace(const RayTracer::Scene &scene, const Maths::Ray &ray)
{
    Maths::Vertex rayColor(1, 1, 1);
    Maths::Vertex incomingLight(0, 0, 0);
    Maths::Ray newRay = ray;

    for (std::size_t i = 0; i < MAX_DEPTH; i++) {
        RayTracer::HitRecord record = this->castRay(scene, newRay);
        if (record._hit) {
            newRay._origin = record._intersection_point;
            newRay._direction = Maths::MathsUtils::getRandomHemisphereDirection(record._normal);

            Maths::Vertex emittedLight = record._material.getEmissionColor();
            emittedLight *= record._material.getEmissionStrength();
            incomingLight += (emittedLight * rayColor);
            rayColor *= record._material.getColor();
        } else {
            incomingLight += (Maths::Vertex(0.25, 0.25, 0.35) * rayColor);
            break;
        }
    }
    return incomingLight;
}

RayTracer::RGBAColor RayTracer::Renderer::cast(const RayTracer::Scene &scene, const Maths::Ray &ray)
{
    Maths::Vertex totalIncomingLight(0, 0, 0);

    for (std::size_t i = 0; i < RAY_PER_PIXEL; i++) {
        totalIncomingLight += this->trace(scene, ray);
    }
    totalIncomingLight /= RAY_PER_PIXEL;
    return RayTracer::RGBAColor(totalIncomingLight._x * 255, totalIncomingLight._y * 255, totalIncomingLight._z * 255);
}

void RayTracer::Renderer::render(const RayTracer::Scene &scene, RayTracer::Frame &frame)
{
    RayTracer::ICamera &camera = *scene.getCamera().get();

    for (std::size_t i = 0; i < frame.getWidth(); i++) {
        for (std::size_t j = 0; j < frame.getHeight(); j++) {
            float x = i / (float)frame.getWidth();
            float y = j / (float)frame.getHeight();
            Maths::Ray ray = camera.ray(x, y);
            frame.setPixel(std::pair<int, int>(i, j), cast(scene, ray));
        }
    }
}
