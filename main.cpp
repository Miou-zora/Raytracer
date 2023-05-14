/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include "SFMLCore.hpp"
#include "BasicCore.hpp"
#include "Core.hpp"

int main(int ac, char **av)
{
    Core core;

    try {
        core.checkArgs(ac, av);
        if (core.isSFML())
            core.runSFML(av[1]);
        else
            core.runBasic(av[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
