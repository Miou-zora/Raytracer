/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Rect3D
*/

#include "Rect3D.hpp"

Maths::Rect3D::Rect3D(void)
{
    _origin = Maths::Vertex(0, 0, 0);
    _bottom_side = Maths::Vertex(1, 0, 0);
    _left_side = Maths::Vertex(0, 0, 1);
}

Maths::Rect3D::Rect3D(const Maths::Vertex &origin, const Maths::Vertex &bottom_side, const Maths::Vertex &left_side)
{
    _origin = origin;
    _bottom_side = bottom_side;
    _left_side = left_side;
}

Maths::Vertex Maths::Rect3D::pointAt(float u, float v) const
{
    return (_origin + (_bottom_side * u) + (_left_side * v));
}

std::ostream &operator<<(std::ostream &stream, const Maths::Rect3D &rect3D)
{
    stream << "Rect3D(" << rect3D._origin << ", " << rect3D._bottom_side << ", " << rect3D._left_side << ")";
    return (stream);
}
