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
            RGBAColor(float r, float g, float b);
            virtual ~RGBAColor() = default;

            RGBAColor &operator=(const RGBAColor &color) = default;
            RGBAColor &operator=(const RGBAColor &&color);

            void setColor(float r, float g, float b);
            void setColor(const RGBAColor &color);
            void setColor(const Maths::Vertex &color);
            void setRed(float r);
            void setGreen(float g);
            void setBlue(float b);
            void setAlpha(float a);

            float getRed(void) const;
            float getGreen(void) const;
            float getBlue(void) const;
            float getAlpha(void) const;
            Maths::Vertex getColor(void) const;

            bool operator==(const RGBAColor &other) const;
            bool operator!=(const RGBAColor &other) const;

        private:
            float _r;
            float _g;
            float _b;
            float _a;
    };
}
