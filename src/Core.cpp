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
#include "Cylinder.hpp"
#include <cmath>

void RayTracer::Core::run(void)
{

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
