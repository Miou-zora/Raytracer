/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Core
*/

#pragma once

#include <string>
#include <iostream>
#include <list>


class Core {
    public:
        Core();
        ~Core();

        void checkArgs(int ac, char **av);
        bool isSFML() const { return _isSFML; };
        void runSFML(std::string scenePath);
        void runBasic(std::string scenePath);
    protected:
    private:
        bool _isSFML;
        bool _isFast;
};
