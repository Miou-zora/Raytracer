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
    setNormal(Maths::Vector(0, 0, 1));
    _normal.rotate(rotation);
}

RayTracer::HitRecord RayTracer::Plane::hit(const Maths::Ray &ray) const
{
    RayTracer::HitRecord hitRecord;
    float denominator = ray._direction.dot(getNormal());

    hitRecord._hit = false;
    if (denominator == 0)
        return hitRecord;
    float t = (getPosition() - ray._origin).dot(VectorToVertex(getNormal())) / denominator;
    if (t < 0)
        return hitRecord;
    hitRecord._intersection_point = ray._origin + ray._direction * t;
    float distance = Maths::MathsUtils::distance(ray._origin, hitRecord._intersection_point);
    if (distance <= 0)
        return hitRecord;
    hitRecord._hit = true;
    hitRecord._distance = distance;
    hitRecord._frontFace = ray._direction.dot(getNormal()) < 0;
    if (hitRecord._frontFace)
        hitRecord._normal = getNormal();
    else
        hitRecord._normal = -getNormal();
    hitRecord._material = getMaterial();
    return hitRecord;
}

