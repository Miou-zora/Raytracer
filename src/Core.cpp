/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Core
*/

#include "Core.hpp"
#include <libconfig.h++>

void RayTracer::Core::run(void)
{
}

void RayTracer::Core::setScene(std::string scenePath)
{
    (void)scenePath;
    // libconfig::Config cfg;

    // if (scenePath.empty())
    //     throw std::invalid_argument("Scene path is empty");
    // try {
    //     cfg.readFile(scenePath.c_str());
    // } catch (const libconfig::FileIOException &fioex) {
    //     throw std::invalid_argument("I/O error while reading file.");
    // }
    // catch (const libconfig::ParseException &pex) {
    //     throw std::invalid_argument("Parse error at " + std::to_string(pex.getLine()) + ": " + pex.getError());
    // }
    // _scenePath = scenePath;
}

void RayTracer::Core::buildScene(void)
{

}

std::shared_ptr<RayTracer::AScene> RayTracer::Core::getScene(void) const
{
    return (nullptr);
}
