/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** RGBColor
*/

#include "RGBColor.hpp"

RayTracer::RGBColor::RGBColor(double r, double g, double b)
{
    _r = r;
    _g = g;
    _b = b;
}


RayTracer::RGBColor::RGBColor(const RayTracer::RGBColor &&color)
{
    _r = color.getRed();
    _g = color.getGreen();
    _b = color.getBlue();
}

RayTracer::RGBColor &RayTracer::RGBColor::operator=(const RayTracer::RGBColor &&color)
{
    _r = color.getRed();
    _g = color.getGreen();
    _b = color.getBlue();
    return *this;
}

void RayTracer::RGBColor::setColor(const RayTracer::RGBColor &color)
{
    _r = color.getRed();
    _g = color.getGreen();
    _b = color.getBlue();
}

void RayTracer::RGBColor::setColor(const Maths::Vertex &color)
{
    _r = color._x;
    _g = color._y;
    _b = color._z;
}

void RayTracer::RGBColor::setColor(double r, double g, double b)
{
    _r = r;
    _g = g;
    _b = b;
}

void RayTracer::RGBColor::setRed(double r)
{
    _r = r;
}

void RayTracer::RGBColor::setGreen(double g)
{
    _g = g;
}

void RayTracer::RGBColor::setBlue(double b)
{
    _b = b;
}

double RayTracer::RGBColor::getRed() const
{
    return _r;
}

double RayTracer::RGBColor::getGreen() const
{
    return _g;
}

double RayTracer::RGBColor::getBlue() const
{
    return _b;
}

Maths::Vertex RayTracer::RGBColor::getColor(void) const
{
    return Maths::Vertex(_r, _g, _b);
}
