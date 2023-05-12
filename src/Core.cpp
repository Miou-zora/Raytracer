/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Core
*/

#include "Core.hpp"

void RayTracer::Core::run(void)
{

}

void RayTracer::Core::build(std::string scenePath)
{
    RayTracer::Builder builder;
    RayTracer::Factory<RayTracer::IShape> shapeFactory;
    RayTracer::Factory<RayTracer::ILight> lightFactory;

    try {
        builder.buildLightFactory(lightFactory);
        builder.buildShapeFactory(shapeFactory);
    } catch (RayTracer::LoaderException &e) {
        std::cerr << e.what() << std::endl;
    }
    builder.buildScene(scenePath, _scene, lightFactory, shapeFactory);
}
