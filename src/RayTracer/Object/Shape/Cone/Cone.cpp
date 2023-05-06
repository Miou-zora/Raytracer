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

    const double cos_theta_squared = pow(cos(_angle), 2);
    const double sin_theta_squared = 1 - cos_theta_squared;
    const double y_diff = ray._origin._y - getPosition()._y;
    const double x_diff = ray._origin._x - getPosition()._x;
    const double z_diff = ray._origin._z - getPosition()._z;

    const double a = cos_theta_squared * pow(ray._direction._y, 2) - sin_theta_squared * (
            pow(ray._direction._x, 2) + pow(ray._direction._z, 2));
    const double b = 2 * cos_theta_squared * ray._direction._y * y_diff - 2 * sin_theta_squared * (
            ray._direction._x * x_diff + ray._direction._z * z_diff);
    const double c = cos_theta_squared * pow(y_diff, 2) - sin_theta_squared * (
            pow(x_diff, 2) + pow(z_diff, 2));
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
        hit_record.setNormal(Maths::Vector(hit_record.getIntersectionPoint()._x - this->getPosition()._x,
                                           hit_record.getIntersectionPoint()._y - this->getPosition()._y,
                                           hit_record.getIntersectionPoint()._z - this->getPosition()._z));
        hit_record.setFrontFace(ray._direction.dot(hit_record.getNormal()) < 0);
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
    hit_record.setNormal(Maths::Vector(hit_record.getIntersectionPoint()._x - this->getPosition()._x,
                                       hit_record.getIntersectionPoint()._y - this->getPosition()._y,
                                       hit_record.getIntersectionPoint()._z - this->getPosition()._z));
    hit_record.setFrontFace(ray._direction.dot(hit_record.getNormal()) < 0);
    hit_record.setMaterial(this->getMaterial());
    return hit_record;
}
