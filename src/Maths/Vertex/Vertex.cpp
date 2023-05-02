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

Maths::Vertex Maths::Vertex::operator+(const double &value)
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

Maths::Vertex Maths::Vertex::operator-(const double &value)
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

Maths::Vertex Maths::Vertex::operator*(const double &value)
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

Maths::Vertex Maths::Vertex::operator/(const double &value)
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


std::ostream &operator<<(std::ostream &out, const Maths::Vertex &vertex)
{
    out << "Vertex(" << vertex._x << ", " << vertex._y << ", " << vertex._z << ")";
    return (out);
}

Maths::Vertex operator-(const Maths::Vertex &vertex1, const Maths::Vertex &vertex2)
{
    return (Maths::Vertex(vertex1._x - vertex2._x, vertex1._y - vertex2._y, vertex1._z - vertex2._z));
}
