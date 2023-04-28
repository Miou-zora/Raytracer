/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** AScene
*/

#pragma once

#include "ICamera.hpp"
#include "ILight.hpp"
#include "IShape.hpp"
#include <vector>
#include <memory>

namespace RayTracer {
    /// @brief AScene class that will contain all the objects of the scene
    class AScene {
        public:
            AScene();
            ~AScene();

            void addShape(const IShape &shape);
            void addLight(const ILight &light);
            void setCamera(const std::shared_ptr<ICamera> &camera);

            std::vector<std::shared_ptr<IShape>> getShapes() const { return _shapes; };
            std::vector<std::shared_ptr<ILight>> getLights() const { return _lights; };
            std::shared_ptr<ICamera> getCamera() const { return _camera; };

        private:
            std::vector<std::shared_ptr<IShape>> _shapes;
            std::vector<std::shared_ptr<ILight>> _lights;
            std::shared_ptr<ICamera> _camera;
    };
}
