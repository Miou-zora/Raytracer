/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** PPMDisplayer
*/

#pragma once

#include "IDisplayer.hpp"
#include <iostream>

namespace RayTracer {
    class PPMDisplayer : virtual public RayTracer::IDisplayer {
        public:
            PPMDisplayer(void) = default;
            virtual ~PPMDisplayer() = default;

            void display(const RayTracer::Frame &frame);

        protected:
        private:
    };
}
