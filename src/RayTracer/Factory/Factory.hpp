/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** Factory
*/

#pragma once

#include <string>
#include "ILight.hpp"
#include "IShape.hpp"
#include <map>
#include <memory>
#include <functional>
#include "LoaderExceptions.hpp"
#include "type.hpp"
#include <libconfig.h++>

namespace RayTracer {
    template <typename ObjectInterface>
    class Factory {
        public:
            Factory() = default;
            ~Factory() = default;

            std::shared_ptr<ObjectInterface> createObject(const std::string& name, libconfig::Setting& setting) {
                auto it = _shapeMap.find(name);
                if (it == _shapeMap.end())
                    throw LoaderException("Object \"" + name + "\" not found");

                return it->second(setting);
            }

            void addObject(const std::string& name, std::function<std::shared_ptr<ObjectInterface>(libconfig::Setting&)> function) {
                _shapeMap.insert(std::make_pair(name, function));
            }

        private:
            std::map<std::string, std::function<std::shared_ptr<ObjectInterface>(libconfig::Setting&)>> _shapeMap;
    };
}

