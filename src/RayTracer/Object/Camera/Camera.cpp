/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Camera
*/

#include "Camera.hpp"

RayTracer::Camera::Camera(void)
{
    _screen = Maths::Rect3D();
    _screen._origin = Maths::Vertex(-0.5, 1, -0.5);
    _screen._bottom_side = Maths::Vertex(0, 0, 1);
    _screen._left_side = Maths::Vertex(1, 0, 0);
    setPosition(Maths::Vertex(0, 0, 0));
    setRotation(Maths::Vertex(0, 0, 0));
}

Maths::Ray RayTracer::Camera::ray(double u, double v) const
{
    Maths::Vertex rotation = this->getRotation();
    Maths::Vertex origin = this->getPosition();
    Maths::Vertex direction = _screen.pointAt(u, v);
    direction = direction.rotate(rotation);

    return (Maths::Ray(origin, Maths::Vector(direction._x, direction._y, direction._z)));
}

