/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** SFMLCore
*/

#include "SFMLCore.hpp"

RayTracer::SFMLCore::SFMLCore(const std::pair<int, int> &windowSize)
{
    _isRunning = true;
    _windowSize = windowSize;
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
    while (_isRunning) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                closeWindow();
        }
        _isRunning = _window.isOpen();
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
