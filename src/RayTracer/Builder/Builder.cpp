/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Builder
*/

#include "Builder.hpp"
#include "ObjectLoader.hpp"
#include "Factory.hpp"
#include "LoaderExceptions.hpp"

void RayTracer::Builder::buildLightFactory(RayTracer::Factory<RayTracer::ILight> &factory)
{
    std::string path = "./lib/";
    std::vector<std::string> libs;
    RayTracer::ObjectLoader<RayTracer::ILight> loader;

    if (!std::filesystem::exists(path))
        throw LoaderException("Error while loading libs");
    try {
        for (const auto &entry : std::filesystem::directory_iterator(path))
            if (entry.path().extension() == ".so" && loader.loadType(path + entry.path().filename().string()) == RayTracer::ObjectType::LIGHT)
                factory.addObject(loader.loadName(path + entry.path().filename().string()), loader.loadObject(path + entry.path().filename().string()));
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << e.what() << std::endl;
        throw LoaderException("Error while loading Light libs");
    }
}

void RayTracer::Builder::buildShapeFactory(RayTracer::Factory<RayTracer::IShape> &factory)
{
    std::string path = "./lib/";
    std::vector<std::string> libs;
    RayTracer::ObjectLoader<RayTracer::IShape> loader;

    if (!std::filesystem::exists(path))
        throw LoaderException("Error while loading libs");
    try {
        for (const auto &entry : std::filesystem::directory_iterator(path))
            if (entry.path().extension() == ".so" && loader.loadType(path + entry.path().filename().string()) == RayTracer::ObjectType::SHAPE)
                factory.addObject(loader.loadName(path + entry.path().filename().string()), loader.loadObject(path + entry.path().filename().string()));
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << e.what() << std::endl;
        throw LoaderException("Error while loading shape libs");
    }
}
