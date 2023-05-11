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
#include "EnhanceRenderer.hpp"
#include "FastRenderer.hpp"
#include "PPMDisplayer.hpp"
#include "DirectionalLight.hpp"
#include <cmath>

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
    flashMaterial.setColor(Maths::Vertex(1, 1, 1));
    flashMaterial.setEmissionColor(Maths::Vertex(1, 1, 1));
    flashMaterial.setEmissionStrength(1);
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

    std::shared_ptr<RayTracer::Camera> camera = std::make_shared<RayTracer::Camera>(RayTracer::Camera(1000, 1000, 80));
    camera->setPosition(Maths::Vertex(0, -1, 0.5));
    camera->setRotation(Maths::Vertex(-M_PI/16, 0, 0));

    std::shared_ptr<RayTracer::DirectionalLight> dLight = std::make_shared<RayTracer::DirectionalLight>(Maths::Vertex(1, 0, 0), 1, Maths::Vector(-1, -1, -1));
    std::shared_ptr<RayTracer::DirectionalLight> dLight2 = std::make_shared<RayTracer::DirectionalLight>(Maths::Vertex(0, 1, 0), 1, Maths::Vector(1, -1, -1));
    std::shared_ptr<RayTracer::DirectionalLight> dLight3 = std::make_shared<RayTracer::DirectionalLight>(Maths::Vertex(0, 0, 1), 1, Maths::Vector(-1, 1, -1));
    std::shared_ptr<RayTracer::DirectionalLight> dLight4 = std::make_shared<RayTracer::DirectionalLight>(Maths::Vertex(1, 1, 1), 1, Maths::Vector(1, 1, -1));

    _scene = std::make_shared<RayTracer::Scene>();
    _scene->addShape(sphere);
    _scene->addShape(sphere2);
    _scene->addShape(sphere3);
    _scene->addShape(sphere4);
    _scene->addShape(plane);
    _scene->setCamera(camera);
    _scene->addLight(dLight);
    _scene->addLight(dLight2);
    _scene->addLight(dLight3);
    _scene->addLight(dLight4);

    RayTracer::Frame frame = RayTracer::Frame(1000, 1000);

    _renderer = std::make_shared<RayTracer::FastRenderer>();
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
