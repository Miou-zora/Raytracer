/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** tests_sphere
*/

#include <criterion/criterion.h>

#include "MathsUtils.hpp"
#include "Sphere.hpp"

Test(sphere, casual) {
    RayTracer::Sphere sphere(Maths::Vertex(0, 0, 0), 1);

    cr_assert(sphere.getPosition() == Maths::Vertex(0, 0, 0));
    cr_assert(sphere.getRadius() == 1);
}

Test(sphere, hit) {
    RayTracer::Sphere sphere(Maths::Vertex(0, 0, 0), 1);
    Maths::Ray ray(Maths::Vertex(0, 0, 0), Maths::Vector(0, 0, 1));

    RayTracer::HitRecord hit = sphere.hit(ray);
    cr_assert(hit._hit);
    cr_assert(hit._material == sphere.getMaterial());
    cr_assert(hit._normal == Maths::Vector(0, 0, -1));
    cr_assert(hit._intersection_point == Maths::Vertex(0, 0, -1));
    cr_assert(hit._frontFace == false);
}

Test(sphere, dontHit) {
    RayTracer::Sphere sphere(Maths::Vertex(100, 100, 100), 1);
    Maths::Ray ray(Maths::Vertex(0, 0, 0), Maths::Vector(0, 0, -1));

    RayTracer::HitRecord hit = sphere.hit(ray);
    cr_assert(hit._hit == false);
}

Test(sphere, hitFrontFace) {
    RayTracer::Sphere sphere(Maths::Vertex(0, 0, 0), 1);
    Maths::Ray ray(Maths::Vertex(0, -2, 0), Maths::Vector(0, 1, 0));

    RayTracer::HitRecord hit = sphere.hit(ray);
    cr_assert(hit._hit);
    cr_assert(hit._material == sphere.getMaterial());
    cr_assert(hit._normal == Maths::Vector(0, -1, 0));
    cr_assert(hit._intersection_point == Maths::Vertex(0, -1, 0));
    cr_assert(hit._frontFace == true);
}

Test(sphere, collide) {
    RayTracer::Sphere sphere(Maths::Vertex(0, 0, 0), 1);
    Maths::Ray ray(Maths::Vertex(0, -1, 0), Maths::Vector(0, 1, 0));

    RayTracer::HitRecord hit = sphere.hit(ray);
    cr_assert(hit._hit);
    cr_assert(hit._material == sphere.getMaterial());
    cr_assert(hit._normal == Maths::Vector(0, -1, 0));
    cr_assert(hit._intersection_point == Maths::Vertex(0, -1, 0));
    cr_assert(hit._frontFace == true);
}

Test(sphere, hitFromBottom) {
    RayTracer::Sphere sphere(Maths::Vertex(0, 0, 0), 1);
    Maths::Ray ray(Maths::Vertex(-1, 0, -1), Maths::Vector(1, 0, 1));

    RayTracer::HitRecord hit = sphere.hit(ray);
    cr_assert(hit._hit);
    cr_assert(hit._material == sphere.getMaterial());
    Maths::Vector normal = hit._normal;
    Maths::Vector expectedNormal = Maths::Vector(-1, 0, -1).normalize();
    cr_assert(static_cast<int>(hit._normal._x * 100000) == static_cast<int>(expectedNormal._x * 100000));
    cr_assert(static_cast<int>(hit._normal._y * 100000) == static_cast<int>(expectedNormal._y * 100000));
    cr_assert(static_cast<int>(hit._normal._z * 100000) == static_cast<int>(expectedNormal._z * 100000));
    Maths::Vertex expectedIntersectionPoint = Maths::Vertex(expectedNormal._x, expectedNormal._y, expectedNormal._z);
    cr_assert(static_cast<int>(hit._intersection_point._x * 100000) == static_cast<int>(expectedIntersectionPoint._x * 100000));
    cr_assert(static_cast<int>(hit._intersection_point._y * 100000) == static_cast<int>(expectedIntersectionPoint._y * 100000));
    cr_assert(static_cast<int>(hit._intersection_point._z * 100000) == static_cast<int>(expectedIntersectionPoint._z * 100000));
    cr_assert(hit._frontFace == true);
    float espectedDistance = Maths::MathsUtils::distance(Maths::Vertex(-1, 0, -1), expectedIntersectionPoint);
    cr_assert(static_cast<int>(hit._distance * 100000) == static_cast<int>(espectedDistance * 100000));
}
