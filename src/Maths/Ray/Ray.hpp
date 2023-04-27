/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Ray
*/

#pragma once

#include "Vertex.hpp"
#include "Vector.hpp"

namespace Maths {
    /**
     * @brief A ray is a line that starts from a point and goes to infinity in a direction.
     */
    class Ray {
        public:
            /**
             * @brief Construct a new Ray object
             */
            Ray(void);

            /**
             * @brief Construct a new Ray object
             *
             * @param origin
             * @param direction
             */
            Ray(const Maths::Vertex &origin, const Maths::Vector &direction);

            /**
             * @brief Destroy the Ray object
             */
            Ray(const Ray &other);

            /**
             * @brief Destroy the Ray object
             */
            Ray(const Ray &&other);

            /**
             * @brief Destroy the Ray object
             */
            ~Ray() = default;

            /**
             * @brief Copy the Ray object with copy operator
             *
             * @param other
             * @return Ray&
             */
            Ray &operator= (const Ray &other);

            /**
             * @brief Copy the Ray object with move operator
             *
             * @param other
             * @return Ray&
             */
            Ray &operator= (const Ray &&other);

            Maths::Vertex _origin;
            Maths::Vector _direction;
    };
}

std::ostream &operator<< (std::ostream &out, const Maths::Ray &ray);
