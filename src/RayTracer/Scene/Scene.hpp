/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Scene
*/

#pragma once

#include "ICamera.hpp"
#include "ILight.hpp"
#include "IShape.hpp"
#include <vector>
#include <memory>

namespace RayTracer {
    /// @brief Scene class that will contain all the objects of the scene
    class Scene {
        public:
            Scene(void) = default;
            ~Scene() = default;

            void addShape(std::shared_ptr<IShape> shape) { _shapes.push_back(shape); };
            void addLight(std::shared_ptr<ILight> light) { _lights.push_back(light); };
            void setCamera(const std::shared_ptr<ICamera> &camera) { _camera = camera; };

            std::vector<std::shared_ptr<IShape>> getShapes(void) const { return _shapes; };
            std::vector<std::shared_ptr<ILight>> getLights(void) const { return _lights; };
            std::shared_ptr<ICamera> getCamera(void) const { return _camera; };

        private:
            std::vector<std::shared_ptr<IShape>> _shapes;
            std::vector<std::shared_ptr<ILight>> _lights;
            std::shared_ptr<ICamera> _camera;
    };
}
