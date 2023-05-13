/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Core
*/

#pragma once

#include <memory>
#include <libconfig.h++>
#include "Camera.hpp"
#include "Scene.hpp"
#include "FastRenderer.hpp"
#include "IDisplayer.hpp"
#include "Vector.hpp"

namespace RayTracer {
    class Core {
        public:
            Core(void) = default;
            virtual ~Core() = default;

            void buildScene(void);
            void run(void);
            void setScenePath(std::string scenePath);
            std::shared_ptr<RayTracer::Scene> getScene(void) const;

        private:

            void initCamera(libconfig::Setting &cameraSetting);
            void setTransformation(libconfig::Setting &setting, RayTracer::Camera &camera);
            void initPrimitives(libconfig::Setting &setting);
            void initLights(libconfig::Setting &setting);

            std::string _scenePath;
            std::shared_ptr<RayTracer::Scene> _scene;
            std::shared_ptr<RayTracer::FastRenderer> _renderer;
            std::shared_ptr<RayTracer::IDisplayer> _displayer;
    };
}
