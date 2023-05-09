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
    _scene = std::make_shared<RayTracer::Scene>();

    cfg.readFile(_scenePath.c_str());
    libconfig::Setting &root = cfg.getRoot();
    try {
        libconfig::Setting &camera = root["camera"];
        initCamera(camera);
        initPrimitives(root);
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
                std::cout << "Sphere" << std::endl;
            } else if (type == "Cylinder") {
                std::cout << "Cylinder" << std::endl;
            } else {
                throw std::invalid_argument("Invalid primitive type in configuration file.");
            }
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        //pass, it not mandatory
    }
    try {
        libconfig::Setting &plane = setting["primitives"]["plane"];
        std::cout << "Plane" << std::endl;
        (void)plane;
    } catch (const libconfig::SettingNotFoundException &nfex) {
        //pass, it not mandatory
    } catch (const std::exception &e) {
        throw std::invalid_argument("Invalid 'plane' setting in configuration file.");
    }
}

std::shared_ptr<RayTracer::Scene> RayTracer::Core::getScene(void) const
{
    return (nullptr);
}
