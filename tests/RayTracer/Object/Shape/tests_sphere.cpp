/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** tests_sphere
*/

#include <criterion/criterion.h>

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
    cr_assert(hit.isHit());
    cr_assert(hit.getMaterial() == RayTracer::Material());
}
