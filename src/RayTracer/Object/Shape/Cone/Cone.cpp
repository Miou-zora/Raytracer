/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Cone
*/

#include "Cone.hpp"
#include "MathsUtils.hpp"
#include <cmath>

RayTracer::Cone::Cone(const Maths::Vertex &position, const double &angle, const double &height,
                      const RayTracer::Material &material)
    : RayTracer::AShape(), _angle(angle), _height(height)
{
    setPosition(position);
    setMaterial(material);
}

RayTracer::HitRecord RayTracer::Cone::hit(const Maths::Ray &ray) const
{
    RayTracer::HitRecord hit_record;

    float a = pow(ray._direction._x, 2) + pow(ray._direction._y, 2) - pow(ray._direction._z, 2) * pow(tan(_angle), 2);
    float b = 2 * (ray._direction._x * (ray._origin._x - getPosition()._x) + ray._direction._y * (ray._origin._y - getPosition()._y) - ray._direction._z * (ray._origin._z - getPosition()._z) * pow(tan(_angle), 2));
    float c = pow(ray._origin._x - getPosition()._x, 2) + pow(ray._origin._y - getPosition()._y, 2) - pow(ray._origin._z - getPosition()._z, 2) * pow(tan(_angle), 2);

    double discriminant = pow(b, 2) - 4 * a * c;

    hit_record.setHit(false);
    if (discriminant < 0)
        return hit_record;
    if (discriminant == 0) {
        double t = -b / (2 * a);
        hit_record.setIntersectionPoint(ray._origin + ray._direction * t);
        double distance = Maths::MathsUtils::distance(ray._origin, hit_record.getIntersectionPoint());
        if (distance < 0)
            return hit_record;
        hit_record.setHit(true);
        hit_record.setDistance(distance);
        Maths::Vector normal = Maths::Vector(
            2 * (hit_record.getIntersectionPoint()._x - getPosition()._x),
            2 * (hit_record.getIntersectionPoint()._y - getPosition()._y),
            2 * pow(tan(_angle), 2) * (hit_record.getIntersectionPoint()._z - getPosition()._z));
        hit_record.setNormal(normal);
        hit_record.setFrontFace(true);
        hit_record.setMaterial(this->getMaterial());

        return hit_record;
    }
    double t1 = (-b + sqrt(discriminant)) / (2 * a);
    double t2 = (-b - sqrt(discriminant)) / (2 * a);
    if (t1 < 0 && t2 < 0) {
        return hit_record;
    }
    double t = t1 < t2 ? t1 : t2;
    hit_record.setIntersectionPoint(ray._origin + ray._direction * t);
    double distance = Maths::MathsUtils::distance(ray._origin, hit_record.getIntersectionPoint());
    if (distance < 0)
        return hit_record;
    hit_record.setHit(true);
    hit_record.setDistance(distance);
    Maths::Vector normal = Maths::Vector(
        2 * (hit_record.getIntersectionPoint()._x - getPosition()._x),
        2 * (hit_record.getIntersectionPoint()._y - getPosition()._y),
        2 * pow(tan(_angle), 2) * (hit_record.getIntersectionPoint()._z - getPosition()._z));
    hit_record.setNormal(normal);
    hit_record.setFrontFace(true);
    hit_record.setMaterial(this->getMaterial());
    return hit_record;
}
