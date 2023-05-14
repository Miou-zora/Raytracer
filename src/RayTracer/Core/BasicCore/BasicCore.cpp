/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** BasicCore
*/

#include <iostream>
#include "Sphere.hpp"
#include "Plane.hpp"
#include "FastRenderer.hpp"
#include "Camera.hpp"
#include "PPMDisplayer.hpp"
#include "Scene.hpp"
#include <cmath>
#include "BasicCore.hpp"
#include "FastRenderer.hpp"
#include "EnhanceRenderer.hpp"
#include "PPMDisplayer.hpp"

void RayTracer::BasicCore::run(void)
{
    RayTracer::Frame frame = RayTracer::Frame(1000, 1000);

    if (_useFastRenderer == false)
        _renderer = std::make_shared<RayTracer::EnhanceRenderer>();
    else if (_useFastRenderer == true)
        _renderer = std::make_shared<RayTracer::FastRenderer>();
    _renderer->render(_scene, frame);
    _displayer = std::make_shared<RayTracer::PPMDisplayer>();
    _displayer->display(frame);
}

void RayTracer::BasicCore::build(std::string scenePath, std::string flag)
{
    RayTracer::Builder builder;

    try {
        builder.setScenePath(scenePath);
        builder.buildScene(_scene);
        if (flag == "-f" || flag == "--fast")
            _useFastRenderer = true;
        else if (flag == "-e" || flag == "--enhance")
            _useFastRenderer = false;
        else
            throw std::invalid_argument("Invalid flag");
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        throw std::invalid_argument("Error while loading scene");
    }
}
