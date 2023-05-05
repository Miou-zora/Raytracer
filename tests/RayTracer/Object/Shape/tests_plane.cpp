/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** tests_plane
*/

#include <criterion/criterion.h>

#include "Plane.hpp"

Test(plane, dontHit) {
    RayTracer::Plane plane;
    Maths::Ray ray(Maths::Vertex(0, 0, 1), Maths::Vector(0, 1, 0));

    RayTracer::HitRecord hit = plane.hit(ray);
    cr_assert(hit._hit == false);
}

Test(plane, hitFrontFace) {
    RayTracer::Plane plane(Maths::Vertex(0, 0, 0));
    Maths::Ray ray(Maths::Vertex(0, 0, 1), Maths::Vector(0, 0, -1));

    RayTracer::HitRecord hit = plane.hit(ray);
    cr_assert(hit._hit);
    cr_assert(hit._material == plane.getMaterial());
    cr_assert(hit._normal == Maths::Vector(0, 0, 1));
    cr_assert(hit._intersection_point == Maths::Vertex(0, 0, 0));
    cr_assert(hit._frontFace == true);
}

Test(plane, hitBackFace) {
    RayTracer::Plane plane(Maths::Vertex(0, 0, 0));
    Maths::Ray ray(Maths::Vertex(0, 0, -1), Maths::Vector(0, 0, 1));

    RayTracer::HitRecord hit = plane.hit(ray);
    cr_assert(hit._hit);
    cr_assert(hit._material == plane.getMaterial());
    cr_assert(hit._normal == Maths::Vector(0, 0, -1));
    cr_assert(hit._intersection_point == Maths::Vertex(0, 0, 0));
    cr_assert(hit._frontFace == false);
}
