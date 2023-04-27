/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Vertex
*/

#pragma once

#include <iostream>

namespace Maths {
    /**
     * @brief Vertex class (x, y, z). It represents a point in 3D space.
     */
    class Vertex {
        public:
            /**
             * @brief Construct a new Vertex object
             */
            Vertex(void) = default;

            /**
             * @brief Construct a new Vertex object
             *
             * @param x
             * @param y
             * @param z
             */
            Vertex(double x, double y, double z);

            /**
             * @brief Destroy the Vertex object
             */
            ~Vertex() = default;

            /**
             * @brief Construct a new Vertex object with copy constructor
             *
             * @param other Vertex to copy
             */
            Vertex(const Vertex &other);

            /**
             * @brief Construct a new Vertex object with move constructor
             *
             * @param other Vertex to move
             */
            Vertex(const Vertex &&other);

            /**
             * @brief Copy the Vertex object with copy operator
             *
             * @param other Vertex to copy
             * @return Vertex& Reference to the copied Vertex
             */
            Vertex &operator= (const Vertex &other);

            /**
             * @brief Copy the Vertex object with move operator
             *
             * @param other Vertex to move
             * @return Vertex& Reference to the moved Vertex
             */
            Vertex &operator= (const Vertex &&other);

            /**
             * @brief Add two Vertex
             *
             * @param other Vertex to add
             * @return Vertex Result of the addition
             */
            Vertex operator+ (const Vertex &other);

            /**
             * @brief Add two Vertex
             *
             * @param other Vertex to add
             * @return Vertex Result of the addition
             */
            Vertex &operator+= (const Vertex &other);

            /**
             * @brief Substract two Vertex
             *
             * @param other Vertex to substract
             * @return Vertex Result of the substraction
             */
            Vertex operator- (const Vertex &other);

            /**
             * @brief Substract two Vertex
             *
             * @param other Vertex to substract
             * @return Vertex Result of the substraction
             */
            Vertex &operator-= (const Vertex &other);

            /**
             * @brief Multiply two Vertex
             *
             * @param other Vertex to multiply
             * @return Vertex Result of the multiplication
             */
            Vertex operator* (const Vertex &other);

            /**
             * @brief Multiply two Vertex
             *
             * @param other Vertex to multiply
             * @return Vertex Result of the multiplication
             */
            Vertex &operator*= (const Vertex &other);

            /**
             * @brief Divide two Vertex
             *
             * @param other Vertex to divide
             * @return Vertex Result of the division
             */
            Vertex operator/ (const Vertex &other);

            /**
             * @brief Divide two Vertex
             *
             * @param other Vertex to divide
             * @return Vertex Result of the division
             */
            Vertex &operator/= (const Vertex &other);

            /**
             * @brief Compare two Vertex
             *
             * @param other Vertex to compare
             * @return true Vertex are the same
             * @return false Vertex are different
             */
            bool operator== (const Vertex &other);

            /**
             * @brief Compare two Vertex
             *
             * @param other Vertex to compare
             * @return true Vertex are different
             * @return false Vertex are the same
             */
            bool operator!= (const Vertex &other);

            /// @brief X coordinate
            double _x;
            /// @brief Y coordinate
            double _y;
            /// @brief Z coordinate
            double _z;
    };
}

std::ostream &operator<< (std::ostream &out, const Maths::Vertex &vertex);
