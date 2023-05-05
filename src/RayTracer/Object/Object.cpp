/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Object
*/

#include "Object.hpp"

void RayTracer::Object::translate(double x, double y, double z)
{
    _position._x += x;
    _position._y += y;
    _position._z += z;
}

void RayTracer::Object::translateX(double x)
{
    _position._x += x;
}

void RayTracer::Object::translateY(double y)
{
    _position._y += y;
}

void RayTracer::Object::translateZ(double z)
{
    _position._z += z;
}

void RayTracer::Object::rotate(double x, double y, double z)
{
    _rotation._x += x;
    _rotation._y += y;
    _rotation._z += z;
}

void RayTracer::Object::rotateX(double x)
{
    _rotation._x += x;
}

void RayTracer::Object::rotateY(double y)
{
    _rotation._y += y;
}

void RayTracer::Object::rotateZ(double z)
{
    _rotation._z += z;
}
