/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Builder
*/

#include <libconfig.h++>
#include "Builder.hpp"
#include "Factory.hpp"
#include "LoaderExceptions.hpp"
#include "Object.hpp"
#include "Camera.hpp"

RayTracer::Builder::Builder()
{

}

RayTracer::Builder::~Builder()
{
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
        //initLights(root, scene);
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::invalid_argument("No 'camera' setting in configuration file.");
    } catch (const std::exception &e) {
        throw std::invalid_argument("Error while building scene: " + std::string(e.what()));
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
        std::string type;
        std::cerr << "Found " << nb_primitive << " shapes."<<std::endl;
        for(int i = 0; i < nb_primitive; ++i) {
            libconfig::Setting &primitive = primitives[i];
            primitive.lookupValue("type", type);
            std::shared_ptr<RayTracer::IShape> shape = _factory.createShape(type, primitive);
            scene.addShape(shape);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        //pass, it not mandatory
    } catch (const std::exception &e) {
        throw std::invalid_argument(std::string(e.what()));
    }
}

void RayTracer::Builder::initLights(libconfig::Setting &setting, RayTracer::Scene &scene)
{
    try {
        libconfig::Setting &lights = setting["lights"];
        int nb_lights = lights.getLength();
        std::string type;

        for(int i = 0; i < nb_lights; ++i) {
            libconfig::Setting &light = lights[i];
            light.lookupValue("type", type);
            std::shared_ptr<RayTracer::ILight> new_light = _factory.createLight(type, light);
            scene.addLight(new_light);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        //pass, it not mandatory
    } catch (const std::exception &e) {
        std::cerr << "An error occured during lights creation because there are not implemented yet. "<< e.what()<< std::endl;
    }
}
