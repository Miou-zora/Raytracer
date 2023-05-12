/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** SFMLCore
*/

#include "SFMLCore.hpp"

RayTracer::SFMLCore::SFMLCore(int width, int height)
{
    _isRunning = true;
    _windowSize = std::make_pair(width, height);
}

RayTracer::SFMLCore::~SFMLCore()
{

}

void RayTracer::SFMLCore::init(void)
{
    createWindow();
}

void RayTracer::SFMLCore::run(void)
{
    createWindow();
    while (_isRunning) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                closeWindow();
        }
        _isRunning = _window.isOpen();
    }
    closeWindow();
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

void RayTracer::SFMLCore::setScene(std::string scenePath)
{
    _scenePath = scenePath;
}

std::shared_ptr<RayTracer::Scene> RayTracer::SFMLCore::getScene(void) const
{
    return (_scene);
}
