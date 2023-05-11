/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** FastRenderer
*/

#include "FastRenderer.hpp"

#include "MathsUtils.hpp"
#include "Vertex.hpp"

RayTracer::FastRenderer::FastRenderer(void) :
    m_ambientLightColor(Maths::Vertex(1, 1, 1)),
    m_ambientLightIntensity(0.2)
{

}

RayTracer::FastRenderer::~FastRenderer()
{

}

RayTracer::HitRecord RayTracer::FastRenderer::getClosestHit(const std::vector<RayTracer::HitRecord> &records) const
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

RayTracer::HitRecord RayTracer::FastRenderer::castRay(const RayTracer::Scene &scene, const Maths::Ray &ray) const
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

Maths::Vertex RayTracer::FastRenderer::findDirectionalLightCoeff(const RayTracer::Scene &scene, const RayTracer::HitRecord &record, const Maths::Ray &ray) const
{
    (void)scene;
    (void)record;
    Maths::Vertex lightAccumulate = Maths::Vertex(0, 0, 0);
    for (const auto &light : scene.getLights()) {
        lightAccumulate += light->hit(record.getIntersectionPoint() - ray._direction * 0.0001, scene, record);
    }
    if (lightAccumulate._x > 1)
        lightAccumulate._x = 1;
    if (lightAccumulate._y > 1)
        lightAccumulate._y = 1;
    if (lightAccumulate._z > 1)
        lightAccumulate._z = 1;
    return (lightAccumulate);
}

RayTracer::RGBAColor RayTracer::FastRenderer::cast(const RayTracer::Scene &scene, const Maths::Ray &ray) const
{
    RayTracer::HitRecord record = this->castRay(scene, ray);
    Maths::Vertex color;

    if (!record.isHit()) {
        return RayTracer::RGBAColor(0, 0, 0);
    }
    Maths::Vertex ambiantLightCoeff = this->m_ambientLightColor * this->m_ambientLightIntensity;
    Maths::Vertex directionalLightCoeff = findDirectionalLightCoeff(scene, record, ray);
    Maths::Vertex lightCoeff = Maths::Vertex(std::max(ambiantLightCoeff._x, directionalLightCoeff._x),
                                            std::max(ambiantLightCoeff._y, directionalLightCoeff._y),
                                            std::max(ambiantLightCoeff._z, directionalLightCoeff._z));
    color = lightCoeff * record.getMaterial().getColor();
    return RayTracer::RGBAColor(color._x * 255, color._y * 255, color._z * 255);
}

void RayTracer::FastRenderer::render(const RayTracer::Scene &scene, RayTracer::Frame &frame)
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
