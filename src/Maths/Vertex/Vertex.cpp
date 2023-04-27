/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Vertex
*/

#include "Vertex.hpp"

Maths::Vertex::Vertex(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

Maths::Vertex::Vertex(const Vertex &other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
}

Maths::Vertex::Vertex(const Vertex &&other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
}

Maths::Vertex &Maths::Vertex::operator=(const Maths::Vertex &other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return (*this);
}

Maths::Vertex &Maths::Vertex::operator=(const Maths::Vertex &&other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return (*this);
}

Maths::Vertex Maths::Vertex::operator+(const Maths::Vertex &other)
{
    return (Maths::Vertex(_x + other._x, _y + other._y, _z + other._z));
}

Maths::Vertex &Maths::Vertex::operator+=(const Maths::Vertex &other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;
    return (*this);
}

Maths::Vertex Maths::Vertex::operator-(const Maths::Vertex &other)
{
    return (Maths::Vertex(_x - other._x, _y - other._y, _z - other._z));
}

Maths::Vertex &Maths::Vertex::operator-=(const Maths::Vertex &other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
    return (*this);
}

Maths::Vertex Maths::Vertex::operator*(const Maths::Vertex &other)
{
    return (Maths::Vertex(_x * other._x, _y * other._y, _z * other._z));
}

Maths::Vertex &Maths::Vertex::operator*=(const Maths::Vertex &other)
{
    _x *= other._x;
    _y *= other._y;
    _z *= other._z;
    return (*this);
}

Maths::Vertex Maths::Vertex::operator/(const Maths::Vertex &other)
{
    return (Maths::Vertex(_x / other._x, _y / other._y, _z / other._z));
}

Maths::Vertex &Maths::Vertex::operator/=(const Maths::Vertex &other)
{
    _x /= other._x;
    _y /= other._y;
    _z /= other._z;
    return (*this);
}

bool Maths::Vertex::operator==(const Maths::Vertex &other)
{
    return (_x == other._x && _y == other._y && _z == other._z);
}

bool Maths::Vertex::operator!=(const Maths::Vertex &other)
{
    return (_x != other._x || _y != other._y || _z != other._z);
}

std::ostream &operator<< (std::ostream &out, const Maths::Vertex &vertex)
{
    out << "Vertex(" << vertex._x << ", " << vertex._y << ", " << vertex._z << ")";
    return (out);
}
