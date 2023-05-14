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
#include "EnhanceRenderer.hpp"
#include "Builder.hpp"
#include <cmath>

RayTracer::SFMLCore::SFMLCore() : _frame(1920, 1080), _useFastRenderer(false)
{
    _isRunning = true;
}

RayTracer::SFMLCore::~SFMLCore()
{
    closeWindow();
}

void RayTracer::SFMLCore::build(std::string scenePath, std::string flag)
{
    RayTracer::Builder builder;
    (void)flag;

    try {
        builder.setScenePath(scenePath);
        builder.buildScene(_scene);
        _useFastRenderer = true;
        _frame = RayTracer::Frame(_scene.getResolution().first, _scene.getResolution().second);
        _windowSize = _scene.getResolution();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        throw std::invalid_argument("Error while loading scene");
    }
    if (_useFastRenderer == false)
        _renderer = std::make_shared<RayTracer::EnhanceRenderer>();
    else
        _renderer = std::make_shared<RayTracer::FastRenderer>();
    createWindow(_scene.getResolution().first, _scene.getResolution().second);
    _displayer = std::make_shared<RayTracer::SFMLDisplayer>(_window);
}

void RayTracer::SFMLCore::run(void)
{
    std::cerr << "Rendering..." << std::endl;
    while (_isRunning) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                closeWindow();
        }
        _isRunning = _window.isOpen();
        if (!_isRunning)
            break;
        _renderer->render(_scene, _frame);
        _displayer->display(_frame);
    }
}

void RayTracer::SFMLCore::createWindow(int width, int height)
{
    _videoMode = sf::VideoMode(width, height);
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
