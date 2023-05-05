/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** ErrorHandling
*/

#pragma once

#include <exception>
#include <string>

namespace RayTracer {
    class InvalidShapeException : public std::exception {
        public:
            InvalidShapeException(const std::string &message) : _message(message) {}
            ~InvalidShapeException() throw() {}
            const char *what() const throw() { return _message.c_str(); }
        private:
            std::string _message;
    };
    class InvalidLightException : public std::exception {
        public:
            InvalidLightException(const std::string &message) : _message(message) {}
            ~InvalidLightException() throw() {}
            const char *what() const throw() { return _message.c_str(); }
        private:
            std::string _message;
    };
}
