/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Ray
*/

#include "Ray.hpp"

Maths::Ray::Ray(void)
{
    _origin = Maths::Vertex();
    _direction = Maths::Vector();
}

Maths::Ray::Ray(const Maths::Vertex &origin, const Maths::Vector &direction)
{
    _origin = origin;
    _direction = direction;
}

Maths::Ray::Ray(const Ray &other)
{
    _origin = other._origin;
    _direction = other._direction;
}

Maths::Ray::Ray(const Ray &&other)
{
    _origin = other._origin;
    _direction = other._direction;
}

Maths::Ray &Maths::Ray::operator= (const Maths::Ray &other)
{
    _origin = other._origin;
    _direction = other._direction;
    return (*this);
}

Maths::Ray &Maths::Ray::operator= (const Maths::Ray &&other)
{
    _origin = other._origin;
    _direction = other._direction;
    return (*this);
}

std::ostream &operator<< (std::ostream &out, const Maths::Ray &ray)
{
    out << "Ray(" << ray._origin << ", " << ray._direction << ")";
    return (out);
}
