/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"
#include "Scene.hpp"

RayTracer::DirectionalLight::DirectionalLight(void)
{
    m_directionalLightColor = Maths::Vertex(1, 1, 1);
    m_directionalLightIntensity = 1;
    m_directionalLightDirection = Maths::Vector(0, 0, -1);
}

RayTracer::DirectionalLight::DirectionalLight(const Maths::Vertex &directionalLightColor, const float &directionalLightIntensity, const Maths::Vector &directionalLightDirection)
{
    m_directionalLightColor = directionalLightColor;
    m_directionalLightIntensity = directionalLightIntensity;
    m_directionalLightDirection = directionalLightDirection.normalized();
}

const Maths::Vertex &RayTracer::DirectionalLight::getDirectionalLightColor() const
{
    return (m_directionalLightColor);
}

void RayTracer::DirectionalLight::setDirectionalLightColor(const Maths::Vertex &directionalLightColor)
{
    m_directionalLightColor = directionalLightColor;
}

const float &RayTracer::DirectionalLight::getDirectionalLightIntensity() const
{
    return (m_directionalLightIntensity);
}

void RayTracer::DirectionalLight::setDirectionalLightIntensity(float directionalLightIntensity)
{
    m_directionalLightIntensity = directionalLightIntensity;
}

const Maths::Vector &RayTracer::DirectionalLight::getDirectionalLightDirection() const
{
    return (m_directionalLightDirection);
}

void RayTracer::DirectionalLight::setDirectionalLightDirection(const Maths::Vector &directionalLightDirection)
{
    m_directionalLightDirection = directionalLightDirection;
}

RayTracer::HitRecord RayTracer::DirectionalLight::getClosestHit(const std::vector<RayTracer::HitRecord> &records) const
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

RayTracer::HitRecord RayTracer::DirectionalLight::castRay(const RayTracer::Scene &scene, const Maths::Ray &ray) const
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

Maths::Vertex RayTracer::DirectionalLight::hit(const Maths::Vertex &position, const RayTracer::Scene &scene, const RayTracer::HitRecord &record) const
{
    Maths::Ray ray(position, -m_directionalLightDirection);

    RayTracer::HitRecord newRecord = this->castRay(scene, ray);

    if (newRecord.isHit()) {
        return (Maths::Vertex(0, 0, 0));
    }
    float coeff = record.getNormal().normalized().dot((-m_directionalLightDirection));
    Maths::Vertex color = m_directionalLightColor * m_directionalLightIntensity * coeff;
    return (color);
}
