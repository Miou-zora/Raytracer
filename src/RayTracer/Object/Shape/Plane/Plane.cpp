/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Plane
*/

#include "Plane.hpp"

#include "MathsUtils.hpp"

RayTracer::Plane::Plane(const Maths::Vertex &position)
{
    setPosition(position);
    setNormal(Maths::Vector(0, 0, 1));
}

RayTracer::Plane::Plane(const Maths::Vertex &position, const RayTracer::Material &material)
{
    setPosition(position);
    setMaterial(material);
    setNormal(Maths::Vector(0, 0, 1));
}

RayTracer::Plane::Plane(const Maths::Vertex &position, const Maths::Vertex &rotation,const RayTracer::Material &material)
{
    setPosition(position);
    setRotation(rotation);
    setMaterial(material);
    _normal.rotate(rotation);
}

RayTracer::HitRecord RayTracer::Plane::hit(const Maths::Ray &ray) const
{
    RayTracer::HitRecord hitRecord;
    double denominator = ray._direction.dot(getNormal());

    hitRecord.setHit(false);
    if (denominator == 0)
        return hitRecord;
    double distance = Maths::MathsUtils::distance(ray._origin, hitRecord.getIntersectionPoint());
    if (distance < 0)
        return hitRecord;
    hitRecord.setDistance(distance);
    hitRecord.setHit(true);
    double t = -(ray._origin.dot(VectorToVertex(getNormal())) + getNormal().dot(VertexToVector(getPosition()))) / denominator;
    hitRecord.setIntersectionPoint(ray._origin + ray._direction * t);
    hitRecord.setNormal(getNormal());
    hitRecord.setFrontFace(ray._direction.dot(hitRecord.getNormal()) < 0);
    hitRecord.setMaterial(getMaterial());
    return hitRecord;
}

