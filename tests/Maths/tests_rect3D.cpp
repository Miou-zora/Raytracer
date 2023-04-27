/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** tests_rect3D
*/

#include <criterion/criterion.h>
#include <cmath>

#include "Rect3D.hpp"

Test(Rect3D, constructor)
{
    Maths::Rect3D rect3D;

    cr_assert(rect3D._origin == Maths::Vertex(0, 0, 0));
    cr_assert(rect3D._bottom_side == Maths::Vertex(1, 0, 0));
    cr_assert(rect3D._left_side == Maths::Vertex(0, 0, 1));
}

Test(Rect3D, constructor_with_params)
{
    Maths::Rect3D rect3D(Maths::Vertex(1, 2, 3), Maths::Vertex(4, 5, 6), Maths::Vertex(7, 8, 9));

    cr_assert(rect3D._origin == Maths::Vertex(1, 2, 3));
    cr_assert(rect3D._bottom_side == Maths::Vertex(4, 5, 6));
    cr_assert(rect3D._left_side == Maths::Vertex(7, 8, 9));
}

Test(Rect3D, pointAt)
{
    Maths::Rect3D rect3D(Maths::Vertex(1, 2, 3), Maths::Vertex(4, 5, 6), Maths::Vertex(7, 8, 9));
    Maths::Vertex vertex = rect3D.pointAt(0.5, 0.5);

    cr_assert(vertex == Maths::Vertex(6.5, 8.5, 10.5));
}

Test(Rect3D, iostream)
{
    Maths::Rect3D rect3D(Maths::Vertex(1, 2, 3), Maths::Vertex(4, 5, 6), Maths::Vertex(7, 8, 9));
    std::stringstream stream;

    stream << rect3D;
    cr_assert(stream.str() == "Rect3D(Vertex(1, 2, 3), Vertex(4, 5, 6), Vertex(7, 8, 9))");
}
