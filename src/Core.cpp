/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Core
*/

#include "Core.hpp"

#include <iostream>
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Camera.hpp"
#include "Renderer.hpp"
#include "PPMDisplayer.hpp"
#include <cmath>

void RayTracer::Core::run(void)
{
    RayTracer::Material redMaterial = RayTracer::Material();
    redMaterial.setColor(RayTracer::RGBAColor(0.8, 0.1, 0.1));
    redMaterial.setEmissionColor(Maths::Vertex(0, 0, 0));
    redMaterial.setEmissionStrength(0);
    RayTracer::Material whiteMaterial = RayTracer::Material();
    whiteMaterial.setColor(RayTracer::RGBAColor(1, 1, 1));
    whiteMaterial.setEmissionColor(Maths::Vertex(0, 0, 0));
    whiteMaterial.setEmissionStrength(0);
    RayTracer::Material greyMaterial = RayTracer::Material();
    greyMaterial.setColor(RayTracer::RGBAColor(0.3, 0.3, 0.3));
    greyMaterial.setEmissionColor(Maths::Vertex(0, 0, 0));
    greyMaterial.setEmissionStrength(0);
    RayTracer::Material flashMaterial = RayTracer::Material();
    flashMaterial.setColor(RayTracer::RGBAColor(0, 0, 0));
    flashMaterial.setEmissionColor(Maths::Vertex(0.5, 0.5, 0.5));
    flashMaterial.setEmissionStrength(2);
    RayTracer::Material greenMaterial = RayTracer::Material();
    greenMaterial.setColor(RayTracer::RGBAColor(0.1, 0.8, 0.1));
    greenMaterial.setEmissionColor(Maths::Vertex(0, 0, 0));
    greenMaterial.setEmissionStrength(0);
    RayTracer::Material blueMaterial = RayTracer::Material();
    blueMaterial.setColor(RayTracer::RGBAColor(0.1, 0.1, 0.8));
    blueMaterial.setEmissionColor(Maths::Vertex(0, 0, 0));
    blueMaterial.setEmissionStrength(0);

    std::shared_ptr<RayTracer::Sphere> sphere = std::make_shared<RayTracer::Sphere>(Maths::Vertex(0, 10, 10), 5, flashMaterial);
    sphere->setRotation(Maths::Vertex(0, 0, 0));

    std::shared_ptr<RayTracer::Sphere> sphere2 = std::make_shared<RayTracer::Sphere>(Maths::Vertex(0.5, 0.5, -0.7), 0.3, redMaterial);
    sphere2->setRotation(Maths::Vertex(0, 0, 0));

    std::shared_ptr<RayTracer::Sphere> sphere3 = std::make_shared<RayTracer::Sphere>(Maths::Vertex(-0.7, 0.4, -0.6), 0.4, whiteMaterial);
    sphere2->setRotation(Maths::Vertex(0, 0, 0));

    std::shared_ptr<RayTracer::Sphere> sphere4 = std::make_shared<RayTracer::Sphere>(Maths::Vertex(0, 0.6, -0.75), 0.25, blueMaterial);
    sphere2->setRotation(Maths::Vertex(0, 0, 0));

    std::shared_ptr<RayTracer::Plane> plane = std::make_shared<RayTracer::Plane>(Maths::Vertex(0, 0, -1), Maths::Vertex(0, 0, 0), greenMaterial);

    std::shared_ptr<RayTracer::Camera> camera = std::make_shared<RayTracer::Camera>(RayTracer::Camera(1920, 1080, 90));
    camera->setPosition(Maths::Vertex(0, -0.5, -0.5));
    camera->setRotation(Maths::Vertex(0, 0, 0));

    _scene = std::make_shared<RayTracer::Scene>();
    _scene->addShape(sphere);
    // _scene->addShape(sphere2);
    _scene->addShape(sphere3);
    // _scene->addShape(sphere4);
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
