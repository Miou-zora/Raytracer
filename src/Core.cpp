/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Core
*/

#include "Core.hpp"
#include "BasicCore.hpp"
#include "SFMLCore.hpp"

Core::Core()
    : _isSFML(false), _isFast(false)
{
}

Core::~Core()
{
}

void Core::checkArgs(int ac, char **av)
{
    if (ac > 4 || ac < 2)
        throw std::invalid_argument("Invalid number of arguments");
    std::list<std::string> args;
    for (int i = 2; i < ac; i++)
        args.push_back(av[i]);
    for (auto &arg : args) {
        if (arg == "-sfml")
            _isSFML = true;
        if (arg == "-ppm")
            _isSFML = false;
        if (arg == "-f" || arg == "--fast")
            _isFast = true;
        if (arg == "-e" || arg == "--enhance")
            _isFast = false;
    }
}

void Core::runSFML(std::string scenePath)
{
    (void)scenePath;
    std::cout << "SFML" << std::endl;
}

void Core::runBasic(std::string scenePath)
{
    RayTracer::BasicCore core;

    try {
        if (_isFast == true) {
            core.build(scenePath);
            std::cerr << "Fast" << std::endl;
        } else {
            core.build(scenePath, "-e");
            std::cerr << "Enhance" << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        throw std::invalid_argument("Error while loading scene");
    }
    core.run();
}
