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
    RayTracer::HitRecord hit_record;

    double a = pow(ray._direction._x, 2) + pow(ray._direction._y, 2);
    double b = 2 * (ray._direction._x * (ray._origin._x - this->getPosition()._x) +
                    ray._direction._y * (ray._origin._y - this->getPosition()._y));
    double c = pow((ray._origin._x - this->getPosition()._x), 2) +
               pow((ray._origin._y - this->getPosition()._y), 2) -
               pow(_radius, 2);
    double discriminant = b * b - 4 * a * c;

    hit_record.setHit(false);
    if (discriminant < 0)
        return hit_record;
    if (discriminant == 0) {
        double t = -b / (2 * a);
        hit_record.setIntersectionPoint(ray._origin + ray._direction * t);
        double distance = Maths::MathsUtils::distance(ray._origin, hit_record.getIntersectionPoint());
        if (distance < 0)
            return hit_record;
        if (hit_record.getIntersectionPoint()._z < this->getPosition()._z || hit_record.getIntersectionPoint()._z > this->getPosition()._z + _height)
            return hit_record;
        hit_record.setHit(true);
        hit_record.setDistance(distance);
        hit_record.setNormal(Maths::Vector(hit_record.getIntersectionPoint()._x - this->getPosition()._x,
                                           0,
                                           hit_record.getIntersectionPoint()._y - this->getPosition()._y));
        hit_record.setFrontFace(ray._direction.dot(hit_record.getNormal()) < 0);
        hit_record.setMaterial(this->getMaterial());

        return hit_record;
    }
    double t1 = (-b + sqrt(discriminant)) / (2 * a);
    double t2 = (-b - sqrt(discriminant)) / (2 * a);
    if (t1 < 0 && t2 < 0) {
        hit_record.setHit(false);
        return hit_record;
    }
    double t = (abs(t1) < abs(t2)) ? t1 : t2;
    hit_record.setIntersectionPoint(ray._origin + ray._direction * t);
    double distance = Maths::MathsUtils::distance(ray._origin, hit_record.getIntersectionPoint());
    hit_record.setDistance(distance);
    if (distance < 0)
        return hit_record;
    hit_record.setHit(true);
    hit_record.setNormal(Maths::Vector(hit_record.getIntersectionPoint()._x - this->getPosition()._x,
                                       0,
                                       hit_record.getIntersectionPoint()._y - this->getPosition()._y));
    hit_record.setFrontFace(true);
    hit_record.setMaterial(this->getMaterial());
    return hit_record;
}