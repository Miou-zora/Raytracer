/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ObjectLoader
*/

#pragma once
namespace Raytracer {
    template <typename ObjectInterface>
        class ObjectLoader {
            public:
                ObjectLoader() {};
                ~ObjectLoader() {};

                std::shared_ptr<ObjectInterface> loadObject(const std::string &objectPath)
                {
                    _handle = dlopen(libPath.c_str(), RTLD_LAZY);
                    ObjectInterface *(*builder)() = nullptr;
                    if (!_handle)
                        throw LoaderException(dlerror());
                    builder = reinterpret_cast<ObjectInterface *(*)()>(dlsym(_handle, "ObjectEntryPoint"));
                    if (!builder)
                        throw LoaderException(dlerror());
                    return std::shared_ptr<ObjectInterface>(builder());
                }

                std::string loadName(const std::string &objectPath)
                {
                    _handle = dlopen(libPath.c_str(), RTLD_LAZY);
                    std::string (*name)() = nullptr;
                    if (!_handle)
                        throw LoaderException(dlerror());
                    name = reinterpret_cast<std::string (*)()>(dlsym(_handle, "NameEntryPoint"));
                    if (!name)
                        throw LoaderException(dlerror());
                    return name();
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
