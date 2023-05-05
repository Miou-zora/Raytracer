/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Cylinder
*/

#include "Cylinder.hpp"
#include <cmath>
#include "MathsUtils.hpp"

RayTracer::Cylinder::Cylinder(const Maths::Vertex &center, double radius, double height)
{
    setPosition(center);
    _radius = radius;
    _height = height;
}

RayTracer::Cylinder::Cylinder(const Maths::Vertex &center, double radius, double height, const RayTracer::Material &material)
{
    setPosition(center);
    _radius = radius;
    _height = height;
    setMaterial(material);
}

RayTracer::HitRecord RayTracer::Cylinder::hit(const Maths::Ray& ray) const
{
}
