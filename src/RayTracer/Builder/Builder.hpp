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

        void buildLightFactory(void) override;
        void buildShapeFactory(void) override;
        void setScenePath(std::string scenePath);
        std::shared_ptr<RayTracer::Scene> getScene(void) const;

        private:
            void initCamera(libconfig::Setting &cameraSetting, RayTracer::Scene &scene);
            void initPrimitives(libconfig::Setting &setting, RayTracer::Scene &scene);
            void initLights(libconfig::Setting &setting, RayTracer::Scene &scene);

            std::string _scenePath;
            RayTracer::Factory<RayTracer::ILight> _lightFactory;
            RayTracer::Factory<RayTracer::IShape> _shapeFactory;
    };
}
