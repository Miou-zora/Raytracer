/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** RGBAColor
*/

#include "RGBAColor.hpp"

RayTracer::RGBAColor::RGBAColor(const RGBAColor &&color)
{
    _r = color.getRed();
    _g = color.getGreen();
    _b = color.getBlue();
    _a = color.getAlpha();
}

RayTracer::RGBAColor::RGBAColor(double r, double g, double b)
{
    _r = r;
    _g = g;
    _b = b;
    _a = 255;
}

RayTracer::RGBAColor &RayTracer::RGBAColor::operator=(const RayTracer::RGBAColor &&color)
{
    _r = color.getRed();
    _g = color.getGreen();
    _b = color.getBlue();
    _a = color.getAlpha();
    return (*this);
}

void RayTracer::RGBAColor::setColor(double r, double g, double b)
{
    _r = r;
    _g = g;
    _b = b;
}

void RayTracer::RGBAColor::setColor(const RayTracer::RGBAColor &color)
{
    _r = color.getRed();
    _g = color.getGreen();
    _b = color.getBlue();
    _a = color.getAlpha();
}

void RayTracer::RGBAColor::setColor(const Maths::Vertex &color)
{
    _r = color._x;
    _g = color._y;
    _b = color._z;
}

void RayTracer::RGBAColor::setRed(double r)
{
    _r = r;
}

void RayTracer::RGBAColor::setGreen(double g)
{
    _g = g;
}

void RayTracer::RGBAColor::setBlue(double b)
{
    _b = b;
}

void RayTracer::RGBAColor::setAlpha(double a)
{
    _a = a;
}

double RayTracer::RGBAColor::getRed(void) const
{
    return (_r);
}

double RayTracer::RGBAColor::getGreen(void) const
{
    return (_g);
}

double RayTracer::RGBAColor::getBlue(void) const
{
    return (_b);
}

double RayTracer::RGBAColor::getAlpha(void) const
{
    return (_a);
}

Maths::Vertex RayTracer::RGBAColor::getColor(void) const
{
    return (Maths::Vertex(_r, _g, _b));
}

bool RayTracer::RGBAColor::operator==(const RayTracer::RGBAColor &other) const
{
    return (_r == other.getRed() && _g == other.getGreen() && _b == other.getBlue());
}

bool RayTracer::RGBAColor::operator!=(const RayTracer::RGBAColor &other) const
{
    return (_r != other.getRed() || _g != other.getGreen() || _b != other.getBlue());
}

