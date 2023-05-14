/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include "Core.hpp"

int main(int ac, char **av)
{
    RayTracer::Core core;
    if (ac != 2 || ac != 3)
        return 84;
    try {
        if (ac == 2)
            core.build(av[1]);
        if (ac == 3)
            core.build(av[1], av[2]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    core.run();
    return 0;
}
