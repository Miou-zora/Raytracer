/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** BasicCore
*/

#pragma once
#include "ICore.hpp"
#include <memory>
#include "Scene.hpp"
#include "IRenderer.hpp"
#include "IDisplayer.hpp"

namespace RayTracer {
    class BasicCore : virtual public ICore {
        public:
            BasicCore(void);
            virtual ~BasicCore();

            void buildScene(void);
            void run(void);
            void setScene(std::string scenePath);
            std::shared_ptr<RayTracer::Scene> getScene(void) const;
        private:
            std::string _scenePath;
            std::shared_ptr<RayTracer::Scene> _scene;
            std::shared_ptr<RayTracer::IRenderer> _renderer;
            std::shared_ptr<RayTracer::IDisplayer> _displayer;
    };
}
