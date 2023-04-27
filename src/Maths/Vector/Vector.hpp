/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Vector
*/

#pragma once

#include <iostream>

namespace Maths {
    class Vector {
        public:
            Vector(void) = default;
            Vector(double x, double y, double z);
            Vector(const Vector &other);
            Vector(const Vector &&other);
            ~Vector() = default;

            Vector &operator= (const Vector &other);
            Vector &operator= (const Vector &&other);
            Vector operator+ (const Vector &other);
            Vector &operator+= (const Vector &other);
            Vector operator- (const Vector &other);
            Vector &operator-= (const Vector &other);
            Vector operator* (const Vector &other);
            Vector &operator*= (const Vector &other);
            Vector operator/ (const Vector &other);
            Vector &operator/= (const Vector &other);
            Vector operator+ (double value);
            Vector &operator+= (double value);
            Vector operator- (double value);
            Vector &operator-= (double value);
            Vector operator* (double value);
            Vector &operator*= (double value);
            Vector operator/ (double value);
            Vector &operator/= (double value);

            double dot(const Vector &other) const;
            Vector cross(const Vector &other) const;
            double length(void) const;
            Vector &normalize(void);
            Vector normalized(void) const;

            double _x;
            double _y;
            double _z;
    };
}

std::iostream &operator<<(std::iostream &stream, const Maths::Vector &vector);
