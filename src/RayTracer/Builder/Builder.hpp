/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Builder
*/

#pragma once

#include "IBuilder.hpp"
#include "LoaderExceptions.hpp"
#include <filesystem>

namespace RayTracer {

    class Builder: public IBuilder {
        public:
            Builder() = default;
            ~Builder() = default;

            void build(RayTracer::Scene &scene) override;
        protected:
        private:
    };
};
