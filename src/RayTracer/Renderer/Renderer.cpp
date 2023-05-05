/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Renderer
*/

#include "Renderer.hpp"
#include "ICamera.hpp"
#include "MathsUtils.hpp"

RayTracer::HitRecord RayTracer::Renderer::getClosestHit(const std::vector<RayTracer::HitRecord> &records) const
{
    double distance = records[0].getDistance();
    RayTracer::HitRecord closestHit = records[0];

    for (const auto &record : records) {
        if (record.getDistance() < distance) {
            distance = record.getDistance();
            closestHit = record;
        }
    }
    return closestHit;
}

RayTracer::HitRecord RayTracer::Renderer::castRay(const RayTracer::Scene &scene, const Maths::Ray &ray) const
{
    std::vector<RayTracer::HitRecord> records;
    RayTracer::HitRecord record;

    for (const auto &shape : scene.getShapes()) {
        record = shape.get()->hit(ray);
        if (record.isHit() && record.isFrontFace()) {
            records.push_back(record);
        }
    }
    if (records.empty()) {
        RayTracer::HitRecord record;
        record.setHit(false);
        return record;
    }
    return this->getClosestHit(records);
}

Maths::Vertex RayTracer::Renderer::trace(const RayTracer::Scene &scene, const Maths::Ray &ray)
{
    Maths::Vertex rayColor(1, 1, 1);
    Maths::Vertex incomingLight(0, 0, 0);
    Maths::Ray newRay = ray;
    for (std::size_t i = 0; i < MAX_DEPTH; i++) {
        RayTracer::HitRecord record = this->castRay(scene, newRay);
        if (!record.isHit()) {
            incomingLight += m_ambientColor * rayColor;
            break;
        }
        newRay._origin = record.getIntersectionPoint();
        newRay._direction = Maths::MathsUtils::getRandomHemisphereDirection(record.getNormal());
        const RayTracer::Material& material = record.getMaterial();
        const Maths::Vertex emittedLight = material.getEmissionColor() * material.getEmissionStrength();
        incomingLight += emittedLight * rayColor;
        rayColor *= material.getColor();
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
            double x = i / (double)frame.getWidth();
            double y = j / (double)frame.getHeight();
            frame.setPixel(std::pair<int, int>(i, j), cast(scene, camera.ray(x, y)));
        }
    }
}
