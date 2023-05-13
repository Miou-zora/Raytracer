/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Convertissor
*/


#include <libconfig.h++>
#include <exception>
#include "Material.hpp"
#include "../../Maths/MathsUtils.hpp"

#pragma once

namespace LoaderExceptions {
    class ConvertissorException: public std::exception {
        public:
            ConvertissorException(const std::string &message): _message(message) {};
            ~ConvertissorException() = default;

            const char *what() const noexcept override {return _message.c_str();}
        private:
            std::string _message;
    };
}

namespace RayTracer {
    class Convertissor {
        public:
            Convertissor() {}
            ~Convertissor() {}

            template<typename T> T get(libconfig::Setting &setting, const std::string name) const
            {
                try {
                    T value;
                    if (!setting.lookupValue(name, value)) {
                        std::cerr << "[WARNING] Cannot find value " << name << std::endl;
                        throw LoaderExceptions::ConvertissorException("Cannot find value " + name);
                    }
                    return value;
                } catch (const libconfig::SettingNotFoundException &e) {
                    std::cerr << "[WARNING] Cannot find value " << name << std::endl;
                    throw LoaderExceptions::ConvertissorException("Cannot find value " + name);
                }
            }

            template<typename T> T get(libconfig::Setting &setting, const std::string name, const T defaultValue) const
            {
                try {
                    T value;
                    if (!setting.lookupValue(name, value)) {
                        std::cerr << "[WARNING] Cannot find value " << name << std::endl;
                        return defaultValue;
                    }
                    return value;
                } catch (const libconfig::SettingNotFoundException &e) {
                    std::cerr << "[WARNING] Cannot find value " << name << std::endl;
                    return defaultValue;
                }
            }

            Maths::Vector ToVector(libconfig::Setting &setting, const std::string &name, Maths::Vector defaultVal=Maths::Vector(0, 0, 0))
            {
                try {
                    setting[name];
                } catch (const libconfig::SettingNotFoundException &e) {
                    std::cerr << "[WARNING] Cannot find vector " << name << std::endl;
                    return defaultVal;
                }
                Maths::Vector vector;
                libconfig::Setting &vectorSetting = setting[name];
                vector._x = get<double>(vectorSetting, "x");
                vector._y = get<double>(vectorSetting, "y");
                vector._z = get<double>(vectorSetting, "z");
                return vector;
            }

            Maths::Vertex ToVertex(libconfig::Setting &setting, const std::string &name, Maths::Vertex defaultVal=Maths::Vertex(0, 0, 0))
            {
                try {
                    setting[name];
                } catch (const libconfig::SettingNotFoundException &e) {
                    std::cerr << "[WARNING] Cannot find vertex " << name << std::endl;
                    return defaultVal;
                }
                libconfig::Setting &vertexSetting = setting[name];
                Maths::Vertex vertex;
                vertex._x = get<double>(vertexSetting, "x", defaultVal._x);
                vertex._y = get<double>(vertexSetting, "y", defaultVal._y);
                vertex._z = get<double>(vertexSetting, "z", defaultVal._z);
                return vertex;
            }

            RayTracer::RGBAColor ToRGBAColor(libconfig::Setting &setting, const std::string &name, RayTracer::RGBAColor defaultVal=RayTracer::RGBAColor(0, 0, 0))
            {
                try {
                    setting[name];
                } catch (const libconfig::SettingNotFoundException &e) {
                    std::cerr << "[WARNING] Cannot find color " << name << std::endl;
                    return defaultVal;
                }
                libconfig::Setting &colorSetting = setting[name];
                RayTracer::RGBAColor color;
                color.setRed(get<double>(colorSetting, "r", defaultVal.getRed()));
                color.setGreen(get<double>(colorSetting, "g", defaultVal.getGreen()));
                color.setBlue(get<double>(colorSetting, "b", defaultVal.getBlue()));
                color.setAlpha(get<double>(colorSetting, "a", defaultVal.getAlpha()));
                return color;
            }

            RayTracer::Material ToMaterial(libconfig::Setting &setting, const std::string name, RayTracer::Material defaultVal = RayTracer::Material())
            {
                try {
                    setting[name];
                } catch (const libconfig::SettingNotFoundException &e) {
                    std::cerr << "[WARNING] Cannot find material " << name << std::endl;
                    return defaultVal;
                }
                RayTracer::Material material;
                libconfig::Setting &materialSetting = setting[name];
                material.setColor(ToVertex(materialSetting, "color", defaultVal.getColor()));
                material.setEmissionColor(ToVertex(materialSetting, "emissionColor", defaultVal.getEmissionColor()));
                material.setEmissionStrength(get<double>(materialSetting, "emissionStrength", defaultVal.getEmissionStrength()));
                material.setSmoothness(get<double>(materialSetting, "smoothness", defaultVal.getSmoothness()));
                return material;
            }
    };
}
