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

double RayTracer::Renderer::getDistance(const std::vector<RayTracer::HitRecord> &records) const
{
    double distance = 0;

    for (auto &record : records) {
        if (record.getDistance() < distance) {
            distance = record.getDistance();
        }
    }
    return distance;
}

RayTracer::HitRecord RayTracer::Renderer::getClosestHit(const std::vector<RayTracer::HitRecord> &records) const
{
    double distance = records[0].getDistance();
    RayTracer::HitRecord closestHit;

    for (auto &record : records) {
        if (record.getDistance() < distance) {
            distance = record.getDistance();
        }
    }
    for (auto &record : records) {
        if (record.getDistance() == distance) {
            closestHit = record;
        }
    }
    return closestHit;
}

RayTracer::RGBAColor RayTracer::Renderer::castRay(const RayTracer::AScene &scene, const Maths::Ray &ray) const
{
    std::vector<RayTracer::HitRecord> records;
    double distance = 0;
    RayTracer::HitRecord closestHit;

    for (auto &shape : scene.getShapes()) {
        RayTracer::HitRecord record = shape.get()->hit(ray);
        if (record.isHit() && record.isFrontFace())
            records.push_back(record);
    }
    if (records.empty())
        return RayTracer::RGBAColor(0, 0, 0, 255);
    closestHit = this->getClosestHit(records);
    return closestHit.getShape()->getColor();
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