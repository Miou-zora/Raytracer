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
#include "FastRenderer.hpp"
#include "PPMDisplayer.hpp"

void RayTracer::Core::run(void)
{
    RayTracer::Frame frame = RayTracer::Frame(1000, 1000);

    _renderer = std::make_shared<RayTracer::FastRenderer>();
    _renderer->render(_scene, frame);
    _displayer = std::make_shared<RayTracer::PPMDisplayer>();
    _displayer->display(frame);
}

void RayTracer::Core::build(std::string scenePath)
{
    RayTracer::Builder builder;

    try {
        builder.setScenePath(scenePath);
        builder.buildScene(_scene);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        throw std::invalid_argument("Error while loading scene");
    }
}
