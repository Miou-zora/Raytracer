/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Vector
*/

#pragma once

#include <iostream>

namespace Maths {
    /**
     * @brief A vector in 3D space
     */
    class Vector {
        public:
            /**
             * @brief Construct a new Vector object
             */
            Vector(void) = default;

            /**
             * @brief Construct a new Vector object
             *
             * @param x
             * @param y
             * @param z
             */
            Vector(double x, double y, double z);

            /**
             * @brief Construct a new Vector object
             *
             * @param other
             */
            Vector(const Vector &other);

            /**
             * @brief Construct a new Vector object
             *
             * @param other
             */
            Vector(const Vector &&other);

            /**
             * @brief Destroy the Vector object
             */
            ~Vector() = default;

            /**
             * @brief Copy the Vector object with copy operator
             *
             * @param other
             * @return Vector&
             */
            Vector &operator= (const Vector &other);

            /**
             * @brief Copy the Vector object with move operator
             *
             * @param other
             * @return Vector&
             */
            Vector &operator= (const Vector &&other);

            /**
             * @brief Add two vectors
             *
             * @param other
             * @return Vector
             */
            Vector operator+ (const Vector &other) const;

            /**
             * @brief Add two vectors
             *
             * @param other
             * @return Vector&
             */
            Vector &operator+= (const Vector &other);

            /**
             * @brief Subtract two vectors
             *
             * @param other
             * @return Vector
             */
            Vector operator- (const Vector &other) const;

            /**
             * @brief Subtract two vectors
             *
             * @param other
             * @return Vector&
             */
            Vector &operator-= (const Vector &other);

            /**
             * @brief Multiply two vectors
             *
             * @param other
             * @return Vector
             */
            Vector operator* (const Vector &other) const;

            /**
             * @brief Multiply two vectors
             *
             * @param other
             * @return Vector&
             */
            Vector &operator*= (const Vector &other);

            /**
             * @brief Divide two vectors
             *
             * @param other
             * @return Vector
             */
            Vector operator/ (const Vector &other) const;

            /**
             * @brief Divide two vectors
             *
             * @param other
             * @return Vector&
             */
            Vector &operator/= (const Vector &other);

            /**
             * @brief Add a value to a vector
             *
             * @param value
             * @return Vector
             */
            Vector operator+ (double value);

            /**
             * @brief Add a value to a vector
             *
             * @param value
             * @return Vector&
             */
            Vector &operator+= (double value);

            /**
             * @brief Subtract a value to a vector
             *
             * @param value
             * @return Vector
             */
            Vector operator- (double value);

            /**
             * @brief Subtract a value to a vector
             *
             * @param value
             * @return Vector&
             */
            Vector &operator-= (double value);

            /**
             * @brief Multiply a vector by a value
             *
             * @param value
             * @return Vector
             */
            Vector operator* (double value);

            /**
             * @brief Multiply a vector by a value
             *
             * @param value
             * @return Vector&
             */
            Vector &operator*= (double value);

            /**
             * @brief Divide a vector by a value
             *
             * @param value
             * @return Vector
             */
            Vector operator/ (double value);

            /**
             * @brief Divide a vector by a value
             *
             * @param value
             * @return Vector&
             */
            Vector &operator/= (double value);

            /**
             * @brief Make the dot product of two vectors
             *
             * @param other The other vector
             * @return double The dot product
             */
            double dot(const Vector &other) const;

            /**
             * @brief Make the cross product of two vectors
             *
             * @param other The other vector
             * @return Vector The cross product
             */
            Vector cross(const Vector &other) const;

            /**
             * @brief Get the length of the vector
             *
             * @return double The length
             */
            double length(void) const;

            /**
             * @brief Normalize the vector
             *
             * @return Vector& The normalized vector
             */
            Vector &normalize(void);

            /**
             * @brief Get the normalized vector
             *
             * @return Vector The normalized vector
             */
            Vector normalized(void) const;

            /**
             * @brief Compare two vectors
             *
             * @param other The other vector
             * @return true If the vectors are the same, false otherwise
             */
            bool operator==(const Vector &other) const;

            /**
             * @brief Compare two vectors
             *
             * @param other The other vector
             * @return false If the vectors are the same, true otherwise
             */
            bool operator!=(const Vector &other) const;

            double _x;
            double _y;
            double _z;
    };
}

std::ostream &operator<<(std::ostream &stream, const Maths::Vector &vector);

Maths::Vector operator-(const Maths::Vector &vector);

