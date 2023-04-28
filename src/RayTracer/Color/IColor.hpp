/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** IColor
*/

#pragma once

#include "Vertex.hpp"

namespace RayTracer {
    class IColor {
        public:
            IColor(void) = default;
            IColor(const IColor &color) = default;
            virtual ~IColor() = default;

            virtual IColor &operator=(const IColor &color) = default;
            virtual IColor &operator=(const IColor &&color) = 0;

            virtual void setColor(double r, double g, double b) = 0;
            virtual void setColor(const Maths::Vertex &color) = 0;
            virtual void setColor(const IColor &color) = 0;

            virtual void setRed(double r) = 0;
            virtual void setGreen(double g) = 0;
            virtual void setBlue(double b) = 0;

            virtual double getRed() const = 0;
            virtual double getGreen() const = 0;
            virtual double getBlue() const = 0;
            virtual Maths::Vertex getColor(void) const = 0;
    };
}
