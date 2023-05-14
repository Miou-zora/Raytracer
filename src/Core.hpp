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
#include "Builder.hpp"
#include "Factory.hpp"
#include "ILight.hpp"
#include "IShape.hpp"
#include "Vector.hpp"

namespace RayTracer
{
    class Core
    {
    public:
        Core(void) : _useFastRenderer(true) {};
        virtual ~Core() = default;

        void run(void);
        void build(std::string scenePath, std::string flag = "-f");
        void setScene(RayTracer::Scene &scene) { this->_scene = scene; };
        RayTracer::Scene getScene(void) const { return _scene; };

    private:
        RayTracer::Scene _scene;
        std::shared_ptr<RayTracer::IRenderer> _renderer;
        std::shared_ptr<RayTracer::IDisplayer> _displayer;
        bool _useFastRenderer;
    };
}
