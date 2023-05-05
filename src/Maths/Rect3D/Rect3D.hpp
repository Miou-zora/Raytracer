/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Rect3D
*/

#pragma once

#include "Vertex.hpp"

namespace Maths {
    class Rect3D {
        public:
            Rect3D(void);
            Rect3D(const Maths::Vertex &origin, const Maths::Vertex &bottom_side, const Maths::Vertex &left_side);
            ~Rect3D() = default;

            Maths::Vertex pointAt(double u, double v) const;

            Maths::Vertex _origin;
            Maths::Vertex _bottom_side;
            Maths::Vertex _left_side;

        protected:
        private:
    };
}

std::ostream &operator<<(std::ostream &stream, const Maths::Rect3D &rect3D);
