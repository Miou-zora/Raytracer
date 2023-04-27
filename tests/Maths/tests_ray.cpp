/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** tests_ray
*/

#include <criterion/criterion.h>

#include "Ray.hpp"

Test(Ray, constructor)
{
    Maths::Ray ray;

    cr_assert(ray._origin == Maths::Vertex());
    cr_assert(ray._direction == Maths::Vector());
}

Test(Ray, constructor_with_params)
{
    Maths::Ray ray(Maths::Vertex(1, 2, 3), Maths::Vector(4, 5, 6));

    cr_assert(ray._origin == Maths::Vertex(1, 2, 3));
    cr_assert(ray._direction == Maths::Vector(4, 5, 6));
}

Test(Ray, copy_constructor)
{
    Maths::Ray ray(Maths::Vertex(1, 2, 3), Maths::Vector(4, 5, 6));
    Maths::Ray ray2(ray);

    cr_assert(ray2._origin == Maths::Vertex(1, 2, 3));
    cr_assert(ray2._direction == Maths::Vector(4, 5, 6));
}

Test(Ray, move_constructor)
{
    Maths::Ray ray(Maths::Vertex(1, 2, 3), Maths::Vector(4, 5, 6));
    Maths::Ray ray2(std::move(ray));

    cr_assert(ray2._origin == Maths::Vertex(1, 2, 3));
    cr_assert(ray2._direction == Maths::Vector(4, 5, 6));
}

Test(Ray, assign_copy)
{
    Maths::Ray ray(Maths::Vertex(1, 2, 3), Maths::Vector(4, 5, 6));
    Maths::Ray ray2(Maths::Vertex(7, 8, 9), Maths::Vector(10, 11, 12));

    ray2 = ray;
    cr_assert(ray2._origin == Maths::Vertex(1, 2, 3));
    cr_assert(ray2._direction == Maths::Vector(4, 5, 6));
}

Test(Ray, assign_move)
{
    Maths::Ray ray(Maths::Vertex(1, 2, 3), Maths::Vector(4, 5, 6));
    Maths::Ray ray2(Maths::Vertex(7, 8, 9), Maths::Vector(10, 11, 12));

    ray2 = std::move(ray);
    cr_assert(ray2._origin == Maths::Vertex(1, 2, 3));
    cr_assert(ray2._direction == Maths::Vector(4, 5, 6));
}

Test(Ray, iostream)
{
    Maths::Ray ray(Maths::Vertex(1, 2, 3), Maths::Vector(4, 5, 6));
    std::stringstream stream;

    stream << ray;
    cr_assert(stream.str() == "Ray(Vertex(1, 2, 3), Vector(4, 5, 6))");
}
