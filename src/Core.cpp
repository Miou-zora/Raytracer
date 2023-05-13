/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Core
*/

#include <iostream>
#include "Sphere.hpp"
#include "Plane.hpp"
#include "FastRenderer.hpp"
#include "Camera.hpp"
#include "PPMDisplayer.hpp"
#include "Scene.hpp"
#include <cmath>
#include "Core.hpp"
#include "RGBAColor.hpp"
#include "Cone.hpp"
#include "DirectionalLight.hpp"

void RayTracer::Core::run(void)
{
    RayTracer::Material redMaterial = RayTracer::Material();
    redMaterial.setColor(Maths::Vertex(0.8, 0.1, 0.1));
    redMaterial.setEmissionColor(Maths::Vertex(0, 0, 0));
    redMaterial.setEmissionStrength(0);
    RayTracer::Material whiteMaterial = RayTracer::Material();
    whiteMaterial.setColor(Maths::Vertex(1, 1, 1));
    whiteMaterial.setEmissionColor(Maths::Vertex(0, 0, 0));
    whiteMaterial.setEmissionStrength(0);
    RayTracer::Material greyMaterial = RayTracer::Material();
    greyMaterial.setColor(Maths::Vertex(0.3, 0.3, 0.3));
    greyMaterial.setEmissionColor(Maths::Vertex(0, 0, 0));
    greyMaterial.setEmissionStrength(0);
    RayTracer::Material flashMaterial = RayTracer::Material();
    flashMaterial.setColor(Maths::Vertex(0, 0, 0));
    flashMaterial.setEmissionColor(Maths::Vertex(0.5, 0.5, 0.5));
    flashMaterial.setEmissionStrength(2);
    RayTracer::Material greenMaterial = RayTracer::Material();
    greenMaterial.setColor(Maths::Vertex(0.1, 0.8, 0.1));
    greenMaterial.setEmissionColor(Maths::Vertex(0, 0, 0));
    greenMaterial.setEmissionStrength(0);
    RayTracer::Material blueMaterial = RayTracer::Material();
    blueMaterial.setColor(Maths::Vertex(0.1, 0.1, 0.8));
    blueMaterial.setEmissionColor(Maths::Vertex(0, 0, 0));
    blueMaterial.setEmissionStrength(0);

    std::shared_ptr<RayTracer::Cone> sphere = std::make_shared<RayTracer::Cone>(Maths::Vertex(0, 10, 0), 0.25, 1, whiteMaterial);
    sphere->setRotation(Maths::Vertex(0, 0, 0));

    std::shared_ptr<RayTracer::Sphere> sphere2 = std::make_shared<RayTracer::Sphere>(Maths::Vertex(0.5, 0.5, -0.85), 0.3, redMaterial);
    sphere2->setRotation(Maths::Vertex(0, 0, 0));

    std::shared_ptr<RayTracer::Cone> sphere3 = std::make_shared<RayTracer::Cone>(Maths::Vertex(-0.7, 3, -0.6), 0.6, 4, whiteMaterial);
    sphere2->setRotation(Maths::Vertex(0, 0, 0));

    std::shared_ptr<RayTracer::Sphere> sphere4 = std::make_shared<RayTracer::Sphere>(Maths::Vertex(0, 0.6, -0.75), 0.25, blueMaterial);
    sphere2->setRotation(Maths::Vertex(0, 0, 0));

    std::shared_ptr<RayTracer::Plane> plane = std::make_shared<RayTracer::Plane>(Maths::Vertex(0, 0, -1), Maths::Vertex(0, 0, 0), greenMaterial);

    std::shared_ptr<RayTracer::DirectionalLight> dlight = std::make_shared<RayTracer::DirectionalLight>(Maths::Vertex(1, 1, 1), 1, Maths::Vector(0, 3, -1));

    std::shared_ptr<RayTracer::Camera> camera = std::make_shared<RayTracer::Camera>(RayTracer::Camera(1000, 1000, 80));
    camera->setPosition(Maths::Vertex(0, -1, 0.5));
    camera->setRotation(Maths::Vertex(-M_PI/16, 0, 0));

    _scene = std::make_shared<RayTracer::Scene>();
    _scene->addShape(sphere);
    _scene->addShape(sphere2);
    // _scene->addShape(sphere3);
    _scene->addShape(sphere4);
    _scene->addShape(plane);
    _scene->setCamera(camera);
    _scene->addLight(dlight);

    RayTracer::Frame frame = RayTracer::Frame(1000, 1000);

    _renderer = std::make_shared<RayTracer::FastRenderer>();
    _renderer->render(*_scene, frame);
    _displayer = std::make_shared<RayTracer::PPMDisplayer>();
    _displayer->display(frame);
}

void RayTracer::Core::setScenePath(std::string scenePath)
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
    _scene = std::make_shared<RayTracer::Scene>();

    cfg.readFile(_scenePath.c_str());
    libconfig::Setting &root = cfg.getRoot();
    try {
        libconfig::Setting &camera = root["camera"];
        initCamera(camera);
        initPrimitives(root);
        initLights(root);
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::invalid_argument("No 'camera' setting in configuration file.");
    } catch (const std::exception &e) {
        throw std::invalid_argument("Error while parsing: " + std::string(e.what()));
    }
}

void RayTracer::Core::initCamera(libconfig::Setting &cameraSetting)
{
    try {
        libconfig::Setting &resolution = cameraSetting["resolution"];
        libconfig::Setting &pos = cameraSetting["position"];
        int width = 0;
        int height = 0;
        int fov = 0;
        Maths::Vector position;

        resolution.lookupValue("width", width);
        resolution.lookupValue("height", height);
        resolution.lookupValue("fov", fov);
        std::shared_ptr<RayTracer::Camera> camera = std::make_shared<RayTracer::Camera>(width, height, fov);
        pos.lookupValue("x", position._x);
        pos.lookupValue("y", position._y);
        pos.lookupValue("z", position._z);
        camera->setPosition(Maths::Vertex(position._x, position._y, position._z));
        setTransformation(cameraSetting, *camera);
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::invalid_argument("Invalid 'camera' setting in configuration file.");
    }
}

void RayTracer::Core::setTransformation(libconfig::Setting &setting, RayTracer::Camera &camera)
{
    try {
        if (setting.exists("rotation")) {
            libconfig::Setting &rotation = setting["rotation"];
            Maths::Vector rotationVector;
            (void) rotation;
            rotation.lookupValue("x", rotationVector._x);
            rotation.lookupValue("y", rotationVector._y);
            rotation.lookupValue("z", rotationVector._z);
            camera.setRotation(Maths::Vertex(rotationVector._x, rotationVector._y, rotationVector._z));
        } else if (setting.exists("translation")) {
            libconfig::Setting &translation = setting["translation"];
            Maths::Vector translationVector;

            translation.lookupValue("x", translationVector._x);
            translation.lookupValue("y", translationVector._y);
            translation.lookupValue("z", translationVector._z);
            camera.setTranslation(Maths::Vertex(translationVector._x, translationVector._y, translationVector._z));
        }
    } catch (const libconfig::SettingTypeException &stex) {
        throw std::invalid_argument("Invalid 'camera' setting type in configuration file.");
    }
}

void RayTracer::Core::initPrimitives(libconfig::Setting &setting)
{
    try {
        libconfig::Setting &primitives = setting["primitives"]["shapes"];
        int nb_primitive = primitives.getLength();
        std::string type;

        for(int i = 0; i < nb_primitive; ++i) {
            libconfig::Setting &primitive = primitives[i];
            primitive.lookupValue("type", type);
            if (type == "Sphere") {
                std::cerr << "Sphere" << std::endl;
            } else if (type == "Cylinder") {
                std::cerr << "Cylinder" << std::endl;
            } else {
                throw std::invalid_argument("Invalid primitive type in configuration file.");
            }
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        //pass, it not mandatory
    }
    try {
        libconfig::Setting &plane = setting["primitives"]["plane"];
        std::cerr << "Plane" << std::endl;
        (void)plane;
    } catch (const libconfig::SettingNotFoundException &nfex) {
        //pass, it not mandatory
    } catch (const std::exception &e) {
        throw std::invalid_argument("Invalid 'plane' setting in configuration file.");
    }
}

void RayTracer::Core::initLights(libconfig::Setting &setting)
{
    try {
        libconfig::Setting &lights = setting["lights"];
        int nb_lights = lights.getLength();
        std::string type;

        for(int i = 0; i < nb_lights; ++i) {
            libconfig::Setting &light = lights[i];
            light.lookupValue("type", type);
            if (type == "Point") {
                std::cerr << "Point" << std::endl;
            } else if (type == "Directional") {
                std::cerr << "Directional" << std::endl;
            } else {
                throw std::invalid_argument("Invalid light type in configuration file.");
            }
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        //pass, it not mandatory
    }
}

std::shared_ptr<RayTracer::Scene> RayTracer::Core::getScene(void) const
{
    return (nullptr);
}
