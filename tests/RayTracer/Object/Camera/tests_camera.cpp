/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** tests_camera
*/

#include <criterion/criterion.h>
#include <cmath>

#include "Camera.hpp"

Test(Camera, casualRay)
{
    RayTracer::Camera camera(1, 1, 28.955);

    Maths::Ray ray = camera.ray(0.5, 0.5);
    cr_assert(ray._origin == Maths::Vertex(0, 0, 0));
    Maths::Vector directionRounded = ray._direction;
    directionRounded._x = round(directionRounded._x * 1000) / 1000;
    directionRounded._y = round(directionRounded._y * 1000) / 1000;
    directionRounded._z = round(directionRounded._z * 1000) / 1000;
    cr_assert(directionRounded == Maths::Vector(0, 1, 0));
}

Test(Camera, rotateRayZ)
{
    RayTracer::Camera camera(1, 1, 28.955);

    camera.setRotation(Maths::Vertex(0, 0, -M_PI / 2));
    Maths::Ray ray = camera.ray(0.5, 0.5);
    cr_assert(ray._origin == Maths::Vertex(0, 0, 0));
    Maths::Vector directionRounded = ray._direction;
    directionRounded._x = round(directionRounded._x * 1000) / 1000;
    directionRounded._y = round(directionRounded._y * 1000) / 1000;
    directionRounded._z = round(directionRounded._z * 1000) / 1000;
    cr_assert(directionRounded == Maths::Vector(1, 0, 0));
}

Test(Camera, rotateRayX)
{
    RayTracer::Camera camera(1, 1, 28.955);

    camera.setRotation(Maths::Vertex(M_PI / 2, 0, 0));
    Maths::Ray ray = camera.ray(0.5, 0.5);
    cr_assert(ray._origin == Maths::Vertex(0, 0, 0));
    Maths::Vector directionRounded = ray._direction;
    directionRounded._x = round(directionRounded._x * 1000) / 1000;
    directionRounded._y = round(directionRounded._y * 1000) / 1000;
    directionRounded._z = round(directionRounded._z * 1000) / 1000;
    cr_assert(directionRounded == Maths::Vector(0, 0, 1));
}

Test(Camera, rotateRayY)
{
    RayTracer::Camera camera(1, 1, 28.955);

    camera.setRotation(Maths::Vertex(0, M_PI / 2, 0));
    Maths::Ray ray = camera.ray(0.5, 0.5);
    cr_assert(ray._origin == Maths::Vertex(0, 0, 0));
    Maths::Vector directionRounded = ray._direction;
    directionRounded._x = round(directionRounded._x * 1000) / 1000;
    directionRounded._y = round(directionRounded._y * 1000) / 1000;
    directionRounded._z = round(directionRounded._z * 1000) / 1000;
    cr_assert(directionRounded == Maths::Vector(0, 1, 0));
}

Test(Camera, rotateRayXZ)
{
    RayTracer::Camera camera(1, 1, 28.955);

    camera.setRotation(Maths::Vertex(M_PI / 2, 0, M_PI / 2));
    Maths::Ray ray = camera.ray(0.5, 0.5);
    cr_assert(ray._origin == Maths::Vertex(0, 0, 0));
    Maths::Vector directionRounded = ray._direction;
    directionRounded._x = round(directionRounded._x * 1000) / 1000;
    directionRounded._y = round(directionRounded._y * 1000) / 1000;
    directionRounded._z = round(directionRounded._z * 1000) / 1000;
    cr_assert(directionRounded == Maths::Vector(0, 0, 1));
}
