/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LoaderExceptions
*/

#pragma once
#include <exception>
#include <string>

namespace RayTracer
{
    /**
     * @brief The class LoaderException is the exception thrown when the library cannot be loaded
     * @param message The message to display
     */
    class LoaderException : public std::exception {
        public:
            LoaderException(const std::string &message) : _message(message) {}
            ~LoaderException() throw() {}
            const char *what() const throw() { return _message.c_str(); }
        private:
            std::string _message;
    };
}