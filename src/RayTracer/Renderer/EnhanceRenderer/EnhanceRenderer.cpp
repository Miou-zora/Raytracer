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

Maths::Vector reflect(const Maths::Vector &v, const Maths::Vector &n)
{
    return v - n * 2 * v.dot(n);
}

Maths::Vector lerp(const Maths::Vector &startValue, const Maths::Vector &endValue, double t)
{
    return startValue + (endValue - startValue) * t;
}

Maths::Vertex RayTracer::EnhanceRenderer::trace(const RayTracer::Scene &scene, const Maths::Ray &ray)
{
    Maths::Vertex rayColor(1, 1, 1);
    Maths::Vertex incomingLight(0, 0, 0);
    Maths::Ray newRay = ray;
    RayTracer::HitRecord record;
    for (std::size_t i = 0; i < MAX_DEPTH; i++) {
        record = this->castRay(scene, newRay);
        if (!record.isHit()) {
            newRay._direction = lerp(newRay._direction, -m_directionalLightDirection, m_directionalFocus);
            newRay._origin = newRay._origin + newRay._direction * -0.0001;
            RayTracer::HitRecord directionalLightRecord = this->castRay(scene, newRay);
            if (!directionalLightRecord.isHit()) {
                Maths::Vertex lightIntensity = Maths::Vertex(std::max(m_ambientColor._x * m_ambientIntensity, m_directionalLightColor._x * m_directionalLightIntensity),
                                                             std::max(m_ambientColor._y * m_ambientIntensity, m_directionalLightColor._y * m_directionalLightIntensity),
                                                             std::max(m_ambientColor._z * m_ambientIntensity, m_directionalLightColor._z * m_directionalLightIntensity));
                incomingLight += lightIntensity * rayColor;
            } else
                incomingLight += m_ambientColor * m_ambientIntensity * rayColor;
            break;
        }
        newRay._origin = record.getIntersectionPoint();
        Maths::Vector diffuseDir = Maths::MathsUtils::getRandomHemisphereDirection(record.getNormal());
        Maths::Vector specularDir = reflect(newRay._direction.normalized(), record.getNormal().normalized());
        newRay._direction = lerp(diffuseDir, specularDir, record.getMaterial().getSmoothness());
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
