/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** RGBAColor
*/

#pragma once

#include "Vertex.hpp"

namespace RayTracer {
    class RGBAColor {
        public:
            RGBAColor(void) = default;
            RGBAColor(const RGBAColor &color) = default;
            RGBAColor(const RGBAColor &&color);
            RGBAColor(double r, double g, double b);
            virtual ~RGBAColor() = default;

            RGBAColor &operator=(const RGBAColor &color) = default;
            RGBAColor &operator=(const RGBAColor &&color);

            void setColor(double r, double g, double b);
            void setColor(const RGBAColor &color);
            void setColor(const Maths::Vertex &color);
            void setRed(double r);
            void setGreen(double g);
            void setBlue(double b);
            void setAlpha(double a);

            double getRed(void) const;
            double getGreen(void) const;
            double getBlue(void) const;
            double getAlpha(void) const;
            Maths::Vertex getColor(void) const;

            bool operator==(const RGBAColor &other) const;
            bool operator!=(const RGBAColor &other) const;

        private:
            double _r;
            double _g;
            double _b;
            double _a;
    };
}
