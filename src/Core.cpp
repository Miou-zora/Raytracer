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

void RayTracer::Core::setScene(std::string scenePath)
{
    libconfig::Config cfg;

    if (scenePath.empty())
        throw std::invalid_argument("Scene path is empty");
    try {
        cfg.readFile(scenePath.c_str());
    } catch (const libconfig::FileIOException &fioex) {
        throw std::invalid_argument("I/O error while reading file.");
    }
    catch (const libconfig::ParseException &pex) {
        throw std::invalid_argument("Parse error at " + std::to_string(pex.getLine()) + ": " + pex.getError());
    }
    _scenePath = scenePath;
}

void RayTracer::Core::buildScene(void)
{
    libconfig::Config cfg;

    cfg.readFile(_scenePath.c_str());
    libconfig::Setting &root = cfg.getRoot();
    try {
        libconfig::Setting &camera = root["camera"];
        initCamera(camera);
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::invalid_argument("No 'camera' setting in configuration file.");
    } catch (const std::exception &e) {
        throw std::invalid_argument("Error while parsing 'camera' setting: " + std::string(e.what()));
    }
}

void RayTracer::Core::initCamera(libconfig::Setting &cameraSetting)
{
    std::shared_ptr<RayTracer::ICamera> camera = std::make_shared<RayTracer::Camera>();
    try {
        libconfig::Setting &position = cameraSetting["position"];
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::invalid_argument("No 'position' setting in 'camera' setting.");
    }
    libconfig::Setting &rotation = cameraSetting["rotation"];

    (void)position;
    (void)rotation;
}

std::shared_ptr<RayTracer::Scene> RayTracer::Core::getScene(void) const
{
    return (nullptr);
}
