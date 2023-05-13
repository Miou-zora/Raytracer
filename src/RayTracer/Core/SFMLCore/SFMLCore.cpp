/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** SFMLCore
*/

#include "SFMLCore.hpp"

#include <iostream>
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Camera.hpp"
#include "FastRenderer.hpp"
#include "DirectionalLight.hpp"
#include "SFMLDisplayer.hpp"
#include <cmath>

RayTracer::SFMLCore::SFMLCore(int width, int height) : _frame(width, height)
{
    _isRunning = true;
    _windowSize = std::make_pair(width, height);
}

RayTracer::SFMLCore::~SFMLCore()
{
    closeWindow();
}

void RayTracer::SFMLCore::init(void)
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

    std::shared_ptr<RayTracer::Sphere> sphere = std::make_shared<RayTracer::Sphere>(Maths::Vertex(0, 40, 5), 10, flashMaterial);
    sphere->setRotation(Maths::Vertex(0, 0, 0));

    std::shared_ptr<RayTracer::Sphere> sphere2 = std::make_shared<RayTracer::Sphere>(Maths::Vertex(0.5, 0.5, -0.85), 0.3, redMaterial);
    sphere2->setRotation(Maths::Vertex(0, 0, 0));

    std::shared_ptr<RayTracer::Sphere> sphere3 = std::make_shared<RayTracer::Sphere>(Maths::Vertex(-0.7, 0.4, -0.6), 0.4, whiteMaterial);
    sphere2->setRotation(Maths::Vertex(0, 0, 0));

    std::shared_ptr<RayTracer::Sphere> sphere4 = std::make_shared<RayTracer::Sphere>(Maths::Vertex(0, 0.6, -0.75), 0.25, blueMaterial);
    sphere2->setRotation(Maths::Vertex(0, 0, 0));

    std::shared_ptr<RayTracer::Plane> plane = std::make_shared<RayTracer::Plane>(Maths::Vertex(0, 0, -1), Maths::Vertex(0, 0, 0), greenMaterial);

    std::shared_ptr<RayTracer::DirectionalLight> dlight = std::make_shared<RayTracer::DirectionalLight>(Maths::Vertex(1, 1, 1), 0.5, Maths::Vector(0, 0, -1));

    std::shared_ptr<RayTracer::Camera> camera = std::make_shared<RayTracer::Camera>(RayTracer::Camera(1000, 1000, 80));
    camera->setPosition(Maths::Vertex(0, -1, 0.5));
    camera->setRotation(Maths::Vertex(-M_PI/16, 0, 0));

    _scene = std::make_shared<RayTracer::Scene>();
    _scene->addShape(sphere);
    _scene->addShape(sphere2);
    _scene->addShape(sphere3);
    _scene->addShape(sphere4);
    _scene->addShape(plane);
    _scene->setCamera(camera);
    _scene->addLight(dlight);

    _renderer = std::make_shared<RayTracer::FastRenderer>();
    _displayer = std::make_shared<RayTracer::SFMLDisplayer>(_window);
    createWindow();
}

void RayTracer::SFMLCore::run(void)
{
    while (_isRunning) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                closeWindow();
        }
        _isRunning = _window.isOpen();
        if (!_isRunning)
            break;
        _renderer->render(*_scene, _frame);
        _displayer->display(_frame);
    }
}

void RayTracer::SFMLCore::createWindow(void)
{
    _videoMode = sf::VideoMode(_windowSize.first, _windowSize.second);
    if (_window.isOpen())
        _window.close();
    _window.create(_videoMode, "Raytracer", sf::Style::Titlebar | sf::Style::Close);
    _isRunning = true;
}

void RayTracer::SFMLCore::closeWindow(void)
{
    _isRunning = false;
    if (_window.isOpen())
        _window.close();
}

void RayTracer::SFMLCore::buildScene(void)
{

}

void RayTracer::SFMLCore::setScenePath(std::string scenePath)
{
    _scenePath = scenePath;
}

std::shared_ptr<RayTracer::Scene> RayTracer::SFMLCore::getScene(void) const
{
    return (_scene);
}
