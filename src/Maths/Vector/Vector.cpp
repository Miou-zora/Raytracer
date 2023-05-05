/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Vector
*/

#include "Vector.hpp"
#include <cmath>

Maths::Vector::Vector(float x, float y, float z)
{
    _x = x;
    _y = y;
    _z = z;
}

Maths::Vector::Vector(const Maths::Vector &other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
}

Maths::Vector::Vector(const Maths::Vector &&other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
}


Maths::Vector &Maths::Vector::operator=(const Maths::Vector &other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return (*this);
}

Maths::Vector &Maths::Vector::operator=(const Maths::Vector &&other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return (*this);
}

Maths::Vector Maths::Vector::operator+(const Maths::Vector &other) const
{
    return (Maths::Vector(_x + other._x, _y + other._y, _z + other._z));
}

Maths::Vector &Maths::Vector::operator+=(const Maths::Vector &other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;
    return (*this);
}

Maths::Vector Maths::Vector::operator-(const Maths::Vector &other) const
{
    return (Maths::Vector(_x - other._x, _y - other._y, _z - other._z));
}

Maths::Vector &Maths::Vector::operator-=(const Maths::Vector &other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
    return (*this);
}

Maths::Vector Maths::Vector::operator*(const Maths::Vector &other) const
{
    return (Maths::Vector(_x * other._x, _y * other._y, _z * other._z));
}

Maths::Vector &Maths::Vector::operator*=(const Maths::Vector &other)
{
    _x *= other._x;
    _y *= other._y;
    _z *= other._z;
    return (*this);
}

Maths::Vector Maths::Vector::operator/(const Maths::Vector &other) const
{
    return (Maths::Vector(_x / other._x, _y / other._y, _z / other._z));
}

Maths::Vector &Maths::Vector::operator/=(const Maths::Vector &other)
{
    _x /= other._x;
    _y /= other._y;
    _z /= other._z;
    return (*this);
}

Maths::Vector Maths::Vector::operator+(float value) const
{
    return (Maths::Vector(_x + value, _y + value, _z + value));
}

Maths::Vector &Maths::Vector::operator+=(float value)
{
    _x += value;
    _y += value;
    _z += value;
    return (*this);
}

Maths::Vector Maths::Vector::operator-(float value) const
{
    return (Maths::Vector(_x - value, _y - value, _z - value));
}

Maths::Vector &Maths::Vector::operator-=(float value)
{
    _x -= value;
    _y -= value;
    _z -= value;
    return (*this);
}

Maths::Vector Maths::Vector::operator*(float value) const
{
    return (Maths::Vector(_x * value, _y * value, _z * value));
}

Maths::Vector &Maths::Vector::operator*=(float value)
{
    _x *= value;
    _y *= value;
    _z *= value;
    return (*this);
}

Maths::Vector Maths::Vector::operator/(float value) const
{
    return (Maths::Vector(_x / value, _y / value, _z / value));
}

Maths::Vector &Maths::Vector::operator/=(float value)
{
    _x /= value;
    _y /= value;
    _z /= value;
    return (*this);
}


float Maths::Vector::dot(const Maths::Vector &other) const
{
    return (_x * other._x + _y * other._y + _z * other._z);
}


Maths::Vector Maths::Vector::cross(const Maths::Vector &other) const
{
    return (Maths::Vector(_y * other._z - _z * other._y,
        _z * other._x - _x * other._z,
        _x * other._y - _y * other._x));
}


float Maths::Vector::length(void) const
{
    return (sqrt(_x * _x + _y * _y + _z * _z));
}


Maths::Vector &Maths::Vector::normalize(void)
{
    float length = this->length();

    _x /= length;
    _y /= length;
    _z /= length;
    return (*this);
}

Maths::Vector Maths::Vector::normalized(void) const
{
    float length = this->length();

    return (Maths::Vector(_x / length, _y / length, _z / length));
}

bool Maths::Vector::operator==(const Maths::Vector &other) const
{
    return (_x == other._x && _y == other._y && _z == other._z);
}

bool Maths::Vector::operator!=(const Maths::Vector &other) const
{
    return (_x != other._x || _y != other._y || _z != other._z);
}

std::ostream &operator<<(std::ostream &stream, const Maths::Vector &vector)
{
    stream << "Vector(" << vector._x << ", " << vector._y << ", " << vector._z
        << ")";
    return (stream);
}

Maths::Vector &Maths::Vector::rotate(const Maths::Vector &rotation)
{
    rotateX(rotation._x);
    rotateY(rotation._y);
    rotateZ(rotation._z);
    return (*this);
}


Maths::Vector &Maths::Vector::rotate(const Maths::Vertex &rotation)
{
    rotateX(rotation._x);
    rotateY(rotation._y);
    rotateZ(rotation._z);
    return (*this);
}

Maths::Vector &Maths::Vector::rotateX(float angle)
{
    float y = _y;
    float z = _z;

    _y = y * cos(angle) - z * sin(angle);
    _z = y * sin(angle) + z * cos(angle);
    return (*this);
}

Maths::Vector &Maths::Vector::rotateY(float angle)
{
    float x = _x;
    float z = _z;

    _x = x * cos(angle) + z * sin(angle);
    _z = -x * sin(angle) + z * cos(angle);
    return (*this);
}

Maths::Vector &Maths::Vector::rotateZ(float angle)
{
    float x = _x;
    float y = _y;

    _x = x * cos(angle) - y * sin(angle);
    _y = x * sin(angle) + y * cos(angle);
    return (*this);
}

Maths::Vector operator-(const Maths::Vector &vector)
{
    return (Maths::Vector(-vector._x, -vector._y, -vector._z));
}
