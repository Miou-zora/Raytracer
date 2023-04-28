/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** AObject
*/

#include "AObject.hpp"

void RayTracer::AObject::translate(double x, double y, double z)
{
    _position._x += x;
    _position._y += y;
    _position._z += z;
}

void RayTracer::AObject::translateX(double x)
{
    _position._x += x;
}

void RayTracer::AObject::translateY(double y)
{
    _position._y += y;
}

void RayTracer::AObject::translateZ(double z)
{
    _position._z += z;
}

void RayTracer::AObject::rotate(double x, double y, double z)
{
    _rotation._x += x;
    _rotation._y += y;
    _rotation._z += z;
}

void RayTracer::AObject::rotateX(double x)
{
    _rotation._x += x;
}

void RayTracer::AObject::rotateY(double y)
{
    _rotation._y += y;
}

void RayTracer::AObject::rotateZ(double z)
{
    _rotation._z += z;
}
