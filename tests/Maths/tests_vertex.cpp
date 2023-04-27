/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** tests_vertex
*/

#include <criterion/criterion.h>

#include "Vertex.hpp"

Test(Vertex, init_xyz)
{
    Maths::Vertex vertex(1, 2, 3);
    cr_assert_eq(vertex._x, 1);
    cr_assert_eq(vertex._y, 2);
    cr_assert_eq(vertex._z, 3);
}

Test(Vertex, init_copy)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(vertex);
    cr_assert_eq(vertex2._x, 1);
    cr_assert_eq(vertex2._y, 2);
    cr_assert_eq(vertex2._z, 3);
}

Test(Vertex, init_move)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(std::move(vertex));
    cr_assert_eq(vertex2._x, 1);
    cr_assert_eq(vertex2._y, 2);
    cr_assert_eq(vertex2._z, 3);
}

Test(Vertex, assign_copy)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(4, 5, 6);
    vertex2 = vertex;
    cr_assert_eq(vertex2._x, 1);
    cr_assert_eq(vertex2._y, 2);
    cr_assert_eq(vertex2._z, 3);
}

Test(Vertex, assign_move)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(4, 5, 6);
    vertex2 = std::move(vertex);
    cr_assert_eq(vertex2._x, 1);
    cr_assert_eq(vertex2._y, 2);
    cr_assert_eq(vertex2._z, 3);
}

Test(Vertex, add)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(4, 5, 6);
    Maths::Vertex vertex3 = vertex + vertex2;
    cr_assert_eq(vertex3._x, 5);
    cr_assert_eq(vertex3._y, 7);
    cr_assert_eq(vertex3._z, 9);
}

Test(Vertex, add_assign)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(4, 5, 6);
    vertex += vertex2;
    cr_assert_eq(vertex._x, 5);
    cr_assert_eq(vertex._y, 7);
    cr_assert_eq(vertex._z, 9);
}

Test(Vertex, sub)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(4, 5, 6);
    Maths::Vertex vertex3 = vertex - vertex2;
    cr_assert_eq(vertex3._x, -3);
    cr_assert_eq(vertex3._y, -3);
    cr_assert_eq(vertex3._z, -3);
}

Test(Vertex, sub_assign)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(4, 5, 6);
    vertex -= vertex2;
    cr_assert_eq(vertex._x, -3);
    cr_assert_eq(vertex._y, -3);
    cr_assert_eq(vertex._z, -3);
}

Test(Vertex, mult)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(4, 5, 6);
    Maths::Vertex vertex3 = vertex * vertex2;
    cr_assert_eq(vertex3._x, 4);
    cr_assert_eq(vertex3._y, 10);
    cr_assert_eq(vertex3._z, 18);
}

Test(Vertex, mult_assign)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(4, 5, 6);
    vertex *= vertex2;
    cr_assert_eq(vertex._x, 4);
    cr_assert_eq(vertex._y, 10);
    cr_assert_eq(vertex._z, 18);
}

Test(Vertex, div)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(4, 5, 6);
    Maths::Vertex vertex3 = vertex / vertex2;
    cr_assert_eq(vertex3._x, 0.25);
    cr_assert_eq(vertex3._y, 0.4);
    cr_assert_eq(vertex3._z, 0.5);
}

Test(Vertex, div_assign)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(4, 5, 6);
    vertex /= vertex2;
    cr_assert_eq(vertex._x, 0.25);
    cr_assert_eq(vertex._y, 0.4);
    cr_assert_eq(vertex._z, 0.5);
}

Test(Vertex, equal)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(1, 2, 3);
    cr_assert_eq(vertex == vertex2, true);
}

Test(Vertex, not_equal)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(4, 5, 6);
    cr_assert_eq(vertex != vertex2, true);
}

Test(Vertex, equal_false)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(1, 2, 3);
    cr_assert_eq(vertex == vertex2, true);
}

Test(Vertex, not_equal_false)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2(1, 2, 3);
    cr_assert_eq(vertex != vertex2, false);
}

Test(Vertex, iostream)
{
    Maths::Vertex vertex(1, 2, 3);
    std::stringstream stream;
    stream << vertex;
    cr_assert_eq(stream.str(), "Vertex(1, 2, 3)");
}

Test(Vertex, add_scalar)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2 = vertex + 1;
    cr_assert_eq(vertex2._x, 2);
    cr_assert_eq(vertex2._y, 3);
    cr_assert_eq(vertex2._z, 4);
}

Test(Vertex, add_scalar_assign)
{
    Maths::Vertex vertex(1, 2, 3);
    vertex += 1;
    cr_assert_eq(vertex._x, 2);
    cr_assert_eq(vertex._y, 3);
    cr_assert_eq(vertex._z, 4);
}

Test(Vertex, sub_scalar)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2 = vertex - 1;
    cr_assert_eq(vertex2._x, 0);
    cr_assert_eq(vertex2._y, 1);
    cr_assert_eq(vertex2._z, 2);
}

Test(Vertex, sub_scalar_assign)
{
    Maths::Vertex vertex(1, 2, 3);
    vertex -= 1;
    cr_assert_eq(vertex._x, 0);
    cr_assert_eq(vertex._y, 1);
    cr_assert_eq(vertex._z, 2);
}

Test(Vertex, mult_scalar)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2 = vertex * 2;
    cr_assert_eq(vertex2._x, 2);
    cr_assert_eq(vertex2._y, 4);
    cr_assert_eq(vertex2._z, 6);
}

Test(Vertex, mult_scalar_assign)
{
    Maths::Vertex vertex(1, 2, 3);
    vertex *= 2;
    cr_assert_eq(vertex._x, 2);
    cr_assert_eq(vertex._y, 4);
    cr_assert_eq(vertex._z, 6);
}

Test(Vertex, div_scalar)
{
    Maths::Vertex vertex(1, 2, 3);
    Maths::Vertex vertex2 = vertex / 2;
    cr_assert_eq(vertex2._x, 0.5);
    cr_assert_eq(vertex2._y, 1);
    cr_assert_eq(vertex2._z, 1.5);
}

Test(Vertex, div_scalar_assign)
{
    Maths::Vertex vertex(1, 2, 3);
    vertex /= 2;
    cr_assert_eq(vertex._x, 0.5);
    cr_assert_eq(vertex._y, 1);
    cr_assert_eq(vertex._z, 1.5);
}
