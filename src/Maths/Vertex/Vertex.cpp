/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Vertex
*/

#include "Vertex.hpp"

#include <cmath>

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

Maths::Vertex Maths::Vertex::operator+(const Maths::Vertex &other) const
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

Maths::Vertex Maths::Vertex::operator-(const Maths::Vertex &other) const
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

Maths::Vertex Maths::Vertex::operator*(const Maths::Vertex &other) const
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

Maths::Vertex Maths::Vertex::operator/(const Maths::Vertex &other) const
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

bool Maths::Vertex::operator==(const Maths::Vertex &other) const
{
    return (_x == other._x && _y == other._y && _z == other._z);
}

bool Maths::Vertex::operator!=(const Maths::Vertex &other) const
{
    return (_x != other._x || _y != other._y || _z != other._z);
}

Maths::Vertex Maths::Vertex::operator+(const double &value) const
{
    return (Maths::Vertex(_x + value, _y + value, _z + value));
}

Maths::Vertex &Maths::Vertex::operator+=(const double &value)
{
    _x += value;
    _y += value;
    _z += value;
    return (*this);
}

Maths::Vertex Maths::Vertex::operator-(const double &value) const
{
    return (Maths::Vertex(_x - value, _y - value, _z - value));
}

Maths::Vertex &Maths::Vertex::operator-=(const double &value)
{
    _x -= value;
    _y -= value;
    _z -= value;
    return (*this);
}

Maths::Vertex Maths::Vertex::operator*(const double &value) const
{
    return (Maths::Vertex(_x * value, _y * value, _z * value));
}

Maths::Vertex &Maths::Vertex::operator*=(const double &value)
{
    _x *= value;
    _y *= value;
    _z *= value;
    return (*this);
}

Maths::Vertex Maths::Vertex::operator/(const double &value) const
{
    return (Maths::Vertex(_x / value, _y / value, _z / value));
}

Maths::Vertex &Maths::Vertex::operator/=(const double &value)
{
    _x /= value;
    _y /= value;
    _z /= value;
    return (*this);
}

Maths::Vertex &Maths::Vertex::rotate(const Maths::Vertex &rotation)
{
    rotateX(rotation._x);
    rotateY(rotation._y);
    rotateZ(rotation._z);
    return (*this);
}

Maths::Vertex &Maths::Vertex::rotateX(const double &angle)
{
    double y = _y;
    double z = _z;

    _y = y * cos(angle) - z * sin(angle);
    _z = y * sin(angle) + z * cos(angle);
    return (*this);
}

Maths::Vertex &Maths::Vertex::rotateY(const double &angle)
{
    double x = _x;
    double z = _z;

    _x = x * cos(angle) + z * sin(angle);
    _z = -x * sin(angle) + z * cos(angle);
    return (*this);
}

Maths::Vertex &Maths::Vertex::rotateZ(const double &angle)
{
    double x = _x;
    double y = _y;

    _x = x * cos(angle) - y * sin(angle);
    _y = x * sin(angle) + y * cos(angle);
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Maths::Vertex &vertex)
{
    out << "Vertex(" << vertex._x << ", " << vertex._y << ", " << vertex._z << ")";
    return (out);
}

