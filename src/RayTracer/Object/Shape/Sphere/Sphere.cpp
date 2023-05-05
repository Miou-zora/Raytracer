/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include <cmath>
#include "MathsUtils.hpp"

RayTracer::Sphere::Sphere(const Maths::Vertex &center, float radius)
{
    setPosition(center);
    _radius = radius;
}

RayTracer::Sphere::Sphere(const Maths::Vertex &center, float radius, const RayTracer::Material &material)
{
    setPosition(center);
    _radius = radius;
    setMaterial(material);
}

RayTracer::HitRecord RayTracer::Sphere::hit(const Maths::Ray &ray) const
{
    RayTracer::HitRecord hit_record;

    float a = ray._direction.dot(ray._direction);
    float b = 2 * (ray._direction._x * (ray._origin._x - this->getPosition()._x) +
                    ray._direction._y * (ray._origin._y - this->getPosition()._y) +
                    ray._direction._z * (ray._origin._z - this->getPosition()._z));
    float c = pow((ray._origin._x - this->getPosition()._x), 2) +
               pow((ray._origin._y - this->getPosition()._y), 2) +
               pow((ray._origin._z - this->getPosition()._z), 2) -
               pow(_radius, 2);
    float discriminant = b * b - 4 * a * c;

    hit_record._hit = false;
    if (discriminant < 0)
        return hit_record;
    if (discriminant == 0) {
        float t = -b / (2 * a);
        hit_record._intersection_point = ray._origin + ray._direction * t;
        float distance = Maths::MathsUtils::distance(ray._origin, hit_record._intersection_point);
        if (distance < 0)
            return hit_record;
        hit_record._hit = true;
        hit_record._distance = distance;
        hit_record._normal = (Maths::Vector(hit_record._intersection_point._x - this->getPosition()._x,
                                           hit_record._intersection_point._y - this->getPosition()._y,
                                           hit_record._intersection_point._z - this->getPosition()._z));
        hit_record._frontFace = ray._direction.dot(hit_record._normal) < 0;
        hit_record._material = this->getMaterial();

        return hit_record;
    }
    float t1 = (-b + sqrt(discriminant)) / (2 * a);
    float t2 = (-b - sqrt(discriminant)) / (2 * a);
    if (t1 < 0 && t2 < 0) {
        hit_record._hit = false;
        return hit_record;
    }
    float t = (abs(t1) < abs(t2)) ? t1 : t2;
    hit_record._intersection_point = ray._origin + ray._direction * t;
    float distance = Maths::MathsUtils::distance(ray._origin, hit_record._intersection_point);
    hit_record._distance = distance;
    if (distance < 0)
        return hit_record;
    hit_record._hit = true;
    hit_record._normal = Maths::Vector(hit_record._intersection_point._x - this->getPosition()._x,
                                       hit_record._intersection_point._y - this->getPosition()._y,
                                       hit_record._intersection_point._z - this->getPosition()._z);
    hit_record._frontFace = ((t1 < 0 && t2 >= 0) || (t1 >= 0 && t2 < 0)) ? false : ray._direction.dot(hit_record._normal) < 0;
    hit_record._material = this->getMaterial();
    return hit_record;
}
