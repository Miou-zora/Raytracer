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
                        RayTracer::Scene &scene) override;

        void buildLightFactory(void) override;
        void buildShapeFactory(void) override;
    protected:
    private:
        RayTracer::Factory<RayTracer::ILight> &_lightFactory;
        RayTracer::Factory<RayTracer::IShape> &_shapeFactory;
    };
}
