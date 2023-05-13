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

namespace RayTracer {
    template <typename ObjectInterface>
        class Factory {
            public:
                Factory(void) = default;
                ~Factory() = default;

                std::shared_ptr<ObjectInterface> createObject(const std::string &name)
                {
                    std::cout << "Available objects:" << std::endl;
                    for (auto &it : _shapeMap) {
                        std::cout << it.first << std::endl;
                    }
                    if (_shapeMap.find(name) == _shapeMap.end())
                        throw LoaderException("Object \"" + name + "\" not found");
                    return _shapeMap[name]();
                }

                void addObject(const std::string &name, std::function<std::shared_ptr<ObjectInterface>()> function) {
                    _shapeMap.insert({name, function});
                }

            protected:
            private:
                std::map<std::string, std::function<std::shared_ptr<ObjectInterface>()>> _shapeMap = {
                };
        };
}
