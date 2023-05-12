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
                T value;

                if (!setting.lookupValue(name, value))
                    throw LoaderExceptions::ConvertissorException("Can't find value " + name);
                return value;
            }

            template<typename T> T get(libconfig::Setting &setting, const std::string name, const T defaultValue) const
            {
                try {
                    T value;

                    if (!setting.lookupValue(name, value))
                        return defaultValue;
                    return value;
                } catch (const libconfig::SettingNotFoundException &e) {
                    return defaultValue;
                }
            }

            Maths::Vector ToVector(libconfig::Setting &setting, Maths::Vector defaultVal=Maths::Vector(0, 0, 0))
            {
                Maths::Vector vector;
                vector._x = get<double>(setting, "x", defaultVal._x);
                vector._y = get<double>(setting, "y", defaultVal._y);
                vector._z = get<double>(setting, "z", defaultVal._z);
                return vector;
            }

            Maths::Vertex ToVertex(libconfig::Setting &setting, const std::string &name, Maths::Vertex defaultVal=Maths::Vertex(0, 0, 0))
            {
                try {
                    setting[name];
                } catch (const libconfig::SettingNotFoundException &e) {
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
                    return defaultVal;
                }
                RayTracer::Material material;
                material.setColor(ToRGBAColor(setting, "color", defaultVal.getColor()));
                material.setDiffuse(get<double>(setting, "diffuse", defaultVal.getDiffuse()));
                material.setSpecular(get<double>(setting, "specular", defaultVal.getSpecular()));
                material.setReflective(get<double>(setting, "reflection", defaultVal.getReflective()));
                return material;
            }
    };
}
