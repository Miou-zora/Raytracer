/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Cylinder
*/

#include "Cylinder.hpp"
#include "MathsUtils.hpp"

RayTracer::Cylinder::Cylinder(const Maths::Vertex &position)
{
    setPosition(position);
    setNormal(Maths::Vector(0, 0, 1));
}

RayTracer::Cylinder::~Cylinder()
{
}

RayTracer::Cylinder::Cylinder(const Maths::Vertex &position, const RayTracer::Material &material)
{
    setPosition(position);
    setMaterial(material);
    setNormal(Maths::Vector(0, 0, 1));
}

RayTracer::Cylinder::Cylinder(const Maths::Vertex &position, const Maths::Vertex &rotation,const RayTracer::Material &material)
{
    setPosition(position);
    setRotation(rotation);
    setMaterial(material);
    setNormal(Maths::Vector(0, 0, 1));
    _normal.rotate(rotation);
}

RayTracer::HitRecord RayTracer::Cylinder::hit(const Maths::Ray &ray) const
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
    hitRecord.setFrontFace(ray._direction.dot(getNormal()) < 0);
    hitRecord.setMaterial(getMaterial());
    return hitRecord;
}
