/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** RGBColor
*/

#pragma once

#include "IColor.hpp"

namespace RayTracer {
    class RGBColor : virtual public RayTracer::IColor {
        public:
            RGBColor(void) = default;
            RGBColor(const RGBColor &color) = default;
            RGBColor(const RGBColor &&color);
            RGBColor(double r, double g, double b);
            virtual ~RGBColor() = default;

            RGBColor &operator=(const RGBColor &color) = default;
            RGBColor &operator=(const RGBColor &&color);

            void setColor(double r, double g, double b);
            void setColor(const RGBColor &color);
            void setColor(const Maths::Vertex &color);
            void setRed(double r);
            void setGreen(double g);
            void setBlue(double b);

            double getRed(void) const;
            double getGreen(void) const;
            double getBlue(void) const;
            Maths::Vertex getColor(void) const;

        private:
            double _r;
            double _g;
            double _b;
    };
}
