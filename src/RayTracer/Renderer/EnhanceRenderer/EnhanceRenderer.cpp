/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** EnhanceRenderer
*/

#include "EnhanceRenderer.hpp"
#include "ICamera.hpp"
#include "MathsUtils.hpp"

RayTracer::HitRecord RayTracer::EnhanceRenderer::getClosestHit(const std::vector<RayTracer::HitRecord> &records) const
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

RayTracer::HitRecord RayTracer::EnhanceRenderer::castRay(const RayTracer::Scene &scene, const Maths::Ray &ray) const
{
    std::vector<RayTracer::HitRecord> records;
    RayTracer::HitRecord record;

    (void)scene;
    for (const auto &shape : scene.getShapes()) {
        record = shape.get()->hit(ray);
        if (record.isHit() && record.isFrontFace()) {
            records.push_back(record);
        }
    }
    if (records.empty()) {
        record.setHit(false);
        return record;
    }
    return this->getClosestHit(records);
}

Maths::Vertex RayTracer::EnhanceRenderer::findLightCoeff(const RayTracer::Scene &scene, const RayTracer::HitRecord &record, const Maths::Ray &ray) const
{
    Maths::Vertex lightAccumulate = Maths::Vertex(0, 0, 0);
    Maths::Ray lerpedRay = ray;

    if (!record.isHit())
        return lightAccumulate;
    lerpedRay._origin = ray._origin - ray._direction * 0.001;
    lerpedRay._direction = Maths::MathsUtils::getRandomHemisphereDirection(record.getNormal());
    for (const auto &light : scene.getLights()) {
        lightAccumulate += light->hit(lerpedRay, scene, record);
    }
    if (lightAccumulate._x > 1)
        lightAccumulate._x = 1;
    if (lightAccumulate._y > 1)
        lightAccumulate._y = 1;
    if (lightAccumulate._z > 1)
        lightAccumulate._z = 1;
    return (lightAccumulate);
}

Maths::Vertex RayTracer::EnhanceRenderer::trace(const RayTracer::Scene &scene, const Maths::Ray &ray)
{
    Maths::Vertex rayColor(1, 1, 1);
    Maths::Vertex incomingLight(0, 0, 0);
    Maths::Ray newRay = ray;
    RayTracer::HitRecord record;
    RayTracer::HitRecord lastRecord;
    Maths::Vertex lightCoeff;
    record.setHit(false);

    for (std::size_t i = 0; i < MAX_DEPTH; i++) {
        lastRecord = record;
        record = this->castRay(scene, newRay);
        if (!record.isHit()) {
            lightCoeff = findLightCoeff(scene, lastRecord, newRay);
            lightCoeff._x = std::max(lightCoeff._x, m_ambientColor._x * m_ambientIntensity);
            lightCoeff._y = std::max(lightCoeff._y, m_ambientColor._y * m_ambientIntensity);
            lightCoeff._z = std::max(lightCoeff._z, m_ambientColor._z * m_ambientIntensity);
            incomingLight += lightCoeff * rayColor;
            break;
        }
        newRay._origin = record.getIntersectionPoint();
        Maths::Vector diffuseDir = Maths::MathsUtils::getRandomHemisphereDirection(record.getNormal());
        Maths::Vector specularDir = Maths::MathsUtils::reflect(newRay._direction.normalized(), record.getNormal().normalized());
        newRay._direction = Maths::MathsUtils::lerp(diffuseDir, specularDir, record.getMaterial().getSmoothness());
        const RayTracer::Material& material = record.getMaterial();
        Maths::Vertex emittedLight = material.getEmissionColor() * material.getEmissionStrength();
        incomingLight += emittedLight * rayColor;
        rayColor *= material.getColor();
    }
    return incomingLight;
}

RayTracer::RGBAColor RayTracer::EnhanceRenderer::cast(const RayTracer::Scene &scene, const Maths::Ray &ray)
{
    Maths::Vertex totalIncomingLight(0, 0, 0);

    for (std::size_t i = 0; i < RAY_PER_PIXEL; i++) {
        totalIncomingLight += this->trace(scene, ray);
    }
    totalIncomingLight /= RAY_PER_PIXEL;
    return RayTracer::RGBAColor(totalIncomingLight._x * 255, totalIncomingLight._y * 255, totalIncomingLight._z * 255);
}

void RayTracer::EnhanceRenderer::render(const RayTracer::Scene &scene, RayTracer::Frame &frame)
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
