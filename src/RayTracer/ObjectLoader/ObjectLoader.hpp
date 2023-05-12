/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ObjectLoader
*/

#pragma once

#include "LoaderExceptions.hpp"
#include "type.hpp"
#include <string>
#include <memory.h>
#include <dlfcn.h>

namespace RayTracer {
    template <typename ObjectInterface>
        class ObjectLoader {
            public:
                ObjectLoader() {};
                ~ObjectLoader() {};

                std::function<std::shared_ptr<ObjectInterface>()> loadObject(const std::string &objectPath)
                {
                    _handle = dlopen(objectPath.c_str(), RTLD_LAZY);
                    ObjectInterface *(*builder)() = nullptr;
                    if (!_handle)
                        throw LoaderException(dlerror());
                    builder = reinterpret_cast<ObjectInterface *(*)()>(dlsym(_handle, "ObjectEntryPoint"));
                    if (!builder)
                        throw LoaderException(dlerror());
                    return [builder]() {
                        return std::shared_ptr<ObjectInterface>(builder());
                    };
                }

                std::string loadName(const std::string &objectPath)
                {
                    _handle = dlopen(objectPath.c_str(), RTLD_LAZY);
                    std::string (*name)() = nullptr;
                    if (!_handle)
                        throw LoaderException(dlerror());
                    name = reinterpret_cast<std::string (*)()>(dlsym(_handle, "NameEntryPoint"));
                    if (!name)
                        throw LoaderException(dlerror());
                    return name();
                }

                RayTracer::ObjectType loadType(const std::string &objectPath)
                {
                    _handle = dlopen(objectPath.c_str(), RTLD_LAZY);
                    RayTracer::ObjectType (*type)() = nullptr;
                    if (!_handle)
                        throw LoaderException(dlerror());
                    type = reinterpret_cast<RayTracer::ObjectType (*)()>(dlsym(_handle, "TypeEntryPoint"));
                    if (!type)
                        throw LoaderException(dlerror());
                    return type();
                }

                void closeLib()
                {
                    if (dlclose(_handle) != 0)
                        throw LoaderException(dlerror());
                }

                bool isLibOpen() const
                {
                    return _handle != nullptr;
                }

                private:
                    void *_handle;
        };
};
