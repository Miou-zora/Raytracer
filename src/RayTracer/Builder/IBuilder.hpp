/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** IBuilder
*/

#pragma once

#include "Scene.hpp"
#include "Factory.hpp"

namespace RayTracer {
    class IBuilder {
        public:
            virtual void buildLightFactory(RayTracer::Factory<RayTracer::ILight> &factory) = 0;
            virtual void buildShapeFactory(RayTracer::Factory<RayTracer::IShape> &factory) = 0;
            virtual void buildScene(std::string sceneFilepath,
                        RayTracer::Scene &scene,
                        RayTracer::Factory<RayTracer::ILight> &lightFactory,
                        RayTracer::Factory<RayTracer::IShape> &shapeFactory) = 0;
    };
}
