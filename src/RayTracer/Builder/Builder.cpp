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

//this function save objects in factory so they can be used in the scene

void RayTracer::Builder::build(RayTracer::Scene &scene)
{
    std::string path = "./lib/";
    std::vector<std::string> libs;
    RayTracer::ObjectLoader loader;
    RayTracer::Factory factory;

    if (!std::filesystem::exists(path))
        throw LoaderException("Error while loading libs");
    try
    {
        for (const auto &entry : std::filesystem::directory_iterator(path))
            if (entry.path().extension() == ".so")
                factory.addObject(loader.loadName(entry), loader.loadObject(entry));
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::cerr << e.what() << std::endl;
        throw LoaderException("Error while loading libs");
    }
}
