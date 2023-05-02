/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Plane
*/

#include "Plane.hpp"

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
    // _normal.rotate(rotation);
}

RayTracer::HitRecord RayTracer::Plane::hit(const Maths::Ray &ray) const
{
    RayTracer::HitRecord hitRecord;
}

