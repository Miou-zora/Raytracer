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
        Builder() = default;
        ~Builder() = default;

        void buildScene(std::string sceneFilepath,
                        RayTracer::Scene &scene,
                        RayTracer::Factory<RayTracer::ILight> &lightFactory,
                        RayTracer::Factory<RayTracer::IShape> &shapeFactory) override;
        void buildLightFactory(RayTracer::Factory<RayTracer::ILight> &factory) override;
        void buildShapeFactory(RayTracer::Factory<RayTracer::IShape> &factory) override;
    protected:
    private:
    };
}
