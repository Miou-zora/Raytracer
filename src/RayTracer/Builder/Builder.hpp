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
    class Builder : public IBuilder {
    public:
        Builder();
        ~Builder();

        void buildScene(RayTracer::Scene &scene) override;

        void setScenePath(std::string scenePath);

        private:
            void initCamera(libconfig::Setting &cameraSetting, RayTracer::Scene &scene);
            void initPrimitives(libconfig::Setting &setting, RayTracer::Scene &scene);
            void initLights(libconfig::Setting &setting, RayTracer::Scene &scene);

            std::string _scenePath;
            RayTracer::Factory _factory;
    };
}
