/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Object
*/

#include "Object.hpp"

void RayTracer::Object::translate(float x, float y, float z)
{
    _position._x += x;
    _position._y += y;
    _position._z += z;
}

void RayTracer::Object::translateX(float x)
{
    _position._x += x;
}

void RayTracer::Object::translateY(float y)
{
    _position._y += y;
}

void RayTracer::Object::translateZ(float z)
{
    _position._z += z;
}

void RayTracer::Object::rotate(float x, float y, float z)
{
    _rotation._x += x;
    _rotation._y += y;
    _rotation._z += z;
}

void RayTracer::Object::rotateX(float x)
{
    _rotation._x += x;
}

void RayTracer::Object::rotateY(float y)
{
    _rotation._y += y;
}

void RayTracer::Object::rotateZ(float z)
{
    _rotation._z += z;
}
