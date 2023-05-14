/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** BasicCore
*/

#pragma once
#include "ICore.hpp"
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
    class BasicCore : public ICore
    {
    public:
        BasicCore(void) : _useFastRenderer(true) {};
        virtual ~BasicCore() = default;

        void run(void);
        void build(std::string scenePath, std::string flag = "-f");
    private:
        RayTracer::Scene _scene;
        std::shared_ptr<RayTracer::IRenderer> _renderer;
        std::shared_ptr<RayTracer::IDisplayer> _displayer;
        bool _useFastRenderer;
    };
}
