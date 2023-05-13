/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Camera
*/

#include "Camera.hpp"
#include "Convertissor.hpp"
#include <cmath>
#include <iostream>

RayTracer::Camera::Camera()
{
    setPosition(Maths::Vertex(0, 0, 0));
    setRotation(Maths::Vertex(0, 0, 0));
    _screen = Maths::Rect3D();
}

RayTracer::Camera::Camera(int width, int height, double fov)
{
    setPosition(Maths::Vertex(0, 0, 0));
    setRotation(Maths::Vertex(0, 0, 0));
    _screen = Maths::Rect3D();

    double aspectRatio = (double)height / (double)width;
    double halfWidth = aspectRatio / 2;
    double distance = (halfWidth * sin((180.0 - fov / 2 - 90.0) * M_PI / 180.0)) / sin(fov * M_PI / 180.0);
    _screen._origin = Maths::Vertex(-0.5 , distance, -halfWidth);
    _screen._left_side = Maths::Vertex(1, 0, 0);
    _screen._bottom_side = Maths::Vertex(0, 0, aspectRatio);
}

Maths::Ray RayTracer::Camera::ray(double x, double y) const
{
    Maths::Vertex rotation = this->getRotation();
    Maths::Vertex origin = this->getPosition();
    Maths::Vertex direction = _screen.pointAt(y, x);
    direction = direction.rotate(rotation);

    return (Maths::Ray(origin, Maths::Vector(direction._x, direction._y, direction._z)));
}

void RayTracer::Camera::loadConfig(libconfig::Setting &setting)
{
    RayTracer::Convertissor Convertissor;

    setPosition(Convertissor.ToVertex(setting, "position"));
    setRotation(Convertissor.ToVertex(setting, "rotation"));
    int width = Convertissor.get<int>(setting, "width", 1920);
    int height = Convertissor.get<int>(setting, "height", 1080);
    double fov = Convertissor.get<double>(setting, "fov", 90.0);
    double aspectRatio = (double)height / (double)width;
    double halfWidth = aspectRatio / 2;
    double distance = (halfWidth * sin((180.0 - fov / 2 - 90.0) * M_PI / 180.0)) / sin(fov * M_PI / 180.0);
    _screen._origin = Maths::Vertex(-0.5 , distance, -halfWidth);
    _screen._left_side = Maths::Vertex(1, 0, 0);
    _screen._bottom_side = Maths::Vertex(0, 0, aspectRatio);
}
