/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Builder
*/

#include <libconfig.h++>
#include "Builder.hpp"
#include "ObjectLoader.hpp"
#include "Factory.hpp"
#include "LoaderExceptions.hpp"
#include "Object.hpp"
#include "Camera.hpp"

RayTracer::Builder::Builder()
{
    buildLightFactory();
    buildShapeFactory();
}

RayTracer::Builder::~Builder()
{
}

void RayTracer::Builder::buildLightFactory()
{
    std::string path = "./lib/";
    RayTracer::Factory<RayTracer::ILight> factory;
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
    _lightFactory = factory;
}

void RayTracer::Builder::buildShapeFactory()
{
    std::string path = "./lib/";
    std::vector<std::string> libs;
    RayTracer::ObjectLoader<RayTracer::IShape> loader;
    RayTracer::Factory<RayTracer::IShape> factory;

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
    _shapeFactory = factory;
}

void RayTracer::Builder::setScenePath(std::string scenePath)
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

void RayTracer::Builder::buildScene(RayTracer::Scene &scene)
{
    libconfig::Config cfg;

    cfg.readFile(_scenePath.c_str());
    libconfig::Setting &root = cfg.getRoot();
    try {
        libconfig::Setting &camera = root["camera"];
        initCamera(camera, scene);
        initPrimitives(root, scene);
        initLights(root, scene);
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::invalid_argument("No 'camera' setting in configuration file.");
    } catch (const std::exception &e) {
        throw std::invalid_argument("Error while parsing: " + std::string(e.what()));
    }
}

void RayTracer::Builder::initCamera(libconfig::Setting &cameraSetting, RayTracer::Scene &scene)
{
    try {
        std::shared_ptr<RayTracer::Camera> camera = std::make_shared<RayTracer::Camera>();
        camera->loadConfig(cameraSetting);
        scene.setCamera(camera);
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::invalid_argument("Invalid 'camera' setting in configuration file.");
    }
}

void RayTracer::Builder::initPrimitives(libconfig::Setting &setting, RayTracer::Scene &scene)
{
    try {
        libconfig::Setting &primitives = setting["primitives"]["shapes"];
        int nb_primitive = primitives.getLength();
        std::string filepath;

        for(int i = 0; i < nb_primitive; ++i) {
            libconfig::Setting &primitive = primitives[i];
            primitive.lookupValue("filepath", filepath);
            std::shared_ptr<RayTracer::IShape> shape = _shapeFactory.createObject(filepath);
            shape->loadConfig(primitives[i]);
            scene.addShape(shape);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        //pass, it not mandatory
    }
}

void RayTracer::Builder::initLights(libconfig::Setting &setting, RayTracer::Scene &scene)
{
    try {
        libconfig::Setting &lights = setting["lights"];
        int nb_lights = lights.getLength();
        std::string filepath;

        for(int i = 0; i < nb_lights; ++i) {
            libconfig::Setting &light = lights[i];
            light.lookupValue("filepath", filepath);
            std::shared_ptr<RayTracer::ILight> new_light = _lightFactory.createObject(filepath);
            new_light->loadConfig(lights[i]);
            scene.addLight(new_light);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        //pass, it not mandatory
    }
}

std::shared_ptr<RayTracer::Scene> RayTracer::Builder::getScene(void) const
{
    return (nullptr);
}
