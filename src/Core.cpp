/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Core
*/

#include <iostream>
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Cone.hpp"
#include "Camera.hpp"
#include "Renderer.hpp"
#include "PPMDisplayer.hpp"
#include <cmath>
#include "Core.hpp"

void RayTracer::Core::run(void)
{
    RayTracer::Material redMaterial = RayTracer::Material();
    redMaterial.setColor(RayTracer::RGBAColor(255, 0, 0));
    RayTracer::Material greenMaterial = RayTracer::Material();
    greenMaterial.setColor(RayTracer::RGBAColor(0, 255, 0));

    std::shared_ptr<RayTracer::Cone> sphere = std::make_shared<RayTracer::Cone>(Maths::Vertex(0, 2, 1), 5, 30, redMaterial);
    sphere->setRotation(Maths::Vertex(0, 0, 0));

    std::shared_ptr<RayTracer::Plane> plane = std::make_shared<RayTracer::Plane>(Maths::Vertex(0, 0, -1), Maths::Vertex(0, 0, 0), greenMaterial);

    std::shared_ptr<RayTracer::Camera> camera = std::make_shared<RayTracer::Camera>(RayTracer::Camera(1920, 1080, 90));
    camera->setRotation(Maths::Vertex(0, 0, 0));

    _scene = std::make_shared<RayTracer::Scene>();
    _scene->addShape(sphere);
    _scene->addShape(plane);
    _scene->setCamera(camera);

    RayTracer::Frame frame = RayTracer::Frame(1920, 1080);

    _renderer = std::make_shared<RayTracer::Renderer>();
    _renderer->render(*_scene, frame);
    _displayer = std::make_shared<RayTracer::PPMDisplayer>();
    _displayer->display(frame);
}

void RayTracer::Core::setScene(std::string scenePath)
{
    (void)scenePath;
}

void RayTracer::Core::buildScene(void)
{

}

std::shared_ptr<RayTracer::Scene> RayTracer::Core::getScene(void) const
{
    return (nullptr);
}
