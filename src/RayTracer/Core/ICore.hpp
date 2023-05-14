/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** ICore
*/

#pragma once

namespace RayTracer {
    class ICore {
        public:
            virtual void run(void) = 0;
            virtual void build(std::string scenePath, std::string flag) = 0;
    };
}
