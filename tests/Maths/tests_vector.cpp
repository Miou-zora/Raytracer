/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** tests_vector
*/

#include <criterion/criterion.h>
#include <cmath>

#include "Vector.hpp"

Test(Vector, init_xyz)
{
    Maths::Vector vector(1, 2, 3);
    cr_assert_eq(vector._x, 1);
    cr_assert_eq(vector._y, 2);
    cr_assert_eq(vector._z, 3);
}

Test(Vector, init_copy)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(vector);
    cr_assert_eq(vector2._x, 1);
    cr_assert_eq(vector2._y, 2);
    cr_assert_eq(vector2._z, 3);
}

Test(Vector, init_move)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(std::move(vector));
    cr_assert_eq(vector2._x, 1);
    cr_assert_eq(vector2._y, 2);
    cr_assert_eq(vector2._z, 3);
}

Test(Vector, assign_copy)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(4, 5, 6);
    vector2 = vector;
    cr_assert_eq(vector2._x, 1);
    cr_assert_eq(vector2._y, 2);
    cr_assert_eq(vector2._z, 3);
}

Test(Vector, assign_move)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(4, 5, 6);
    vector2 = std::move(vector);
    cr_assert_eq(vector2._x, 1);
    cr_assert_eq(vector2._y, 2);
    cr_assert_eq(vector2._z, 3);
}

Test(Vector, add)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(4, 5, 6);
    Maths::Vector vector3 = vector + vector2;
    cr_assert_eq(vector3._x, 5);
    cr_assert_eq(vector3._y, 7);
    cr_assert_eq(vector3._z, 9);
}

Test(Vector, sub)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(4, 5, 6);
    Maths::Vector vector3 = vector - vector2;
    cr_assert_eq(vector3._x, -3);
    cr_assert_eq(vector3._y, -3);
    cr_assert_eq(vector3._z, -3);
}

Test(Vector, mul)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(4, 5, 6);
    Maths::Vector vector3 = vector * vector2;
    cr_assert_eq(vector3._x, 4);
    cr_assert_eq(vector3._y, 10);
    cr_assert_eq(vector3._z, 18);
}

Test(Vector, div)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(4, 5, 6);
    Maths::Vector vector3 = vector / vector2;
    cr_assert_eq(vector3._x, 0.25);
    cr_assert_eq(vector3._y, 0.4);
    cr_assert_eq(vector3._z, 0.5);
}

Test(Vector, add_eq)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(4, 5, 6);
    vector += vector2;
    cr_assert_eq(vector._x, 5);
    cr_assert_eq(vector._y, 7);
    cr_assert_eq(vector._z, 9);
}

Test(Vector, sub_eq)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(4, 5, 6);
    vector -= vector2;
    cr_assert_eq(vector._x, -3);
    cr_assert_eq(vector._y, -3);
    cr_assert_eq(vector._z, -3);
}

Test(Vector, mul_eq)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(4, 5, 6);
    vector *= vector2;
    cr_assert_eq(vector._x, 4);
    cr_assert_eq(vector._y, 10);
    cr_assert_eq(vector._z, 18);
}

Test(Vector, div_eq)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(4, 5, 6);
    vector /= vector2;
    cr_assert_eq(vector._x, 0.25);
    cr_assert_eq(vector._y, 0.4);
    cr_assert_eq(vector._z, 0.5);
}

Test(Vector, add_scalar)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2 = vector + 2;
    cr_assert_eq(vector2._x, 3);
    cr_assert_eq(vector2._y, 4);
    cr_assert_eq(vector2._z, 5);
}

Test(Vector, sub_scalar)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2 = vector - 2;
    cr_assert_eq(vector2._x, -1);
    cr_assert_eq(vector2._y, 0);
    cr_assert_eq(vector2._z, 1);
}

Test(Vector, mul_scalar)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2 = vector * 2;
    cr_assert_eq(vector2._x, 2);
    cr_assert_eq(vector2._y, 4);
    cr_assert_eq(vector2._z, 6);
}

Test(Vector, div_scalar)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2 = vector / 2;
    cr_assert_eq(vector2._x, 0.5);
    cr_assert_eq(vector2._y, 1);
    cr_assert_eq(vector2._z, 1.5);
}

Test(Vector, add_scalar_eq)
{
    Maths::Vector vector(1, 2, 3);
    vector += 2;
    cr_assert_eq(vector._x, 3);
    cr_assert_eq(vector._y, 4);
    cr_assert_eq(vector._z, 5);
}

Test(Vector, sub_scalar_eq)
{
    Maths::Vector vector(1, 2, 3);
    vector -= 2;
    cr_assert_eq(vector._x, -1);
    cr_assert_eq(vector._y, 0);
    cr_assert_eq(vector._z, 1);
}

Test(Vector, mul_scalar_eq)
{
    Maths::Vector vector(1, 2, 3);
    vector *= 2;
    cr_assert_eq(vector._x, 2);
    cr_assert_eq(vector._y, 4);
    cr_assert_eq(vector._z, 6);
}

Test(Vector, div_scalar_eq)
{
    Maths::Vector vector(1, 2, 3);
    vector /= 2;
    cr_assert_eq(vector._x, 0.5);
    cr_assert_eq(vector._y, 1);
    cr_assert_eq(vector._z, 1.5);
}

Test(Vector, dot)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(4, 5, 6);
    float dot = vector.dot(vector2);
    cr_assert_eq(dot, 32);
}

Test(Vector, cross)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2(4, 5, 6);
    Maths::Vector vector3 = vector.cross(vector2);
    cr_assert_eq(vector3._x, -3);
    cr_assert_eq(vector3._y, 6);
    cr_assert_eq(vector3._z, -3);
}

Test(Vector, length)
{
    Maths::Vector vector(1, 2, 3);
    float length = vector.length();
    cr_assert_eq(static_cast<int>(length * 1000000), static_cast<int>(sqrt(14) * 1000000));
}

Test(Vector, normalize)
{
    Maths::Vector vector(1, 2, 3);
    vector.normalize();
    cr_assert_eq(static_cast<int>(vector._x * 1000000), static_cast<int>(0.26726124 * 1000000));
    cr_assert_eq(static_cast<int>(vector._y * 1000000), static_cast<int>(0.53452247 * 1000000));
    cr_assert_eq(static_cast<int>(vector._z * 1000000), static_cast<int>(0.80178368 * 1000000));
}

Test(Vector, normalized)
{
    Maths::Vector vector(1, 2, 3);
    Maths::Vector vector2 = vector.normalized();
    cr_assert_eq(static_cast<int>(vector2._x * 1000000), static_cast<int>(0.26726124 * 1000000));
    cr_assert_eq(static_cast<int>(vector2._y * 1000000), static_cast<int>(0.53452247 * 1000000));
    cr_assert_eq(static_cast<int>(vector2._z * 1000000), static_cast<int>(0.80178368 * 1000000));
    cr_assert_eq(vector._x, 1);
    cr_assert_eq(vector._y, 2);
    cr_assert_eq(vector._z, 3);
}

Test(Vector, iostream)
{
    Maths::Vector vector(1, 2, 3);
    std::stringstream stream;
    stream << vector;
    cr_assert_str_eq(stream.str().c_str(), "Vector(1, 2, 3)");
}
