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
    if (ac != 2)
        return 84;
    try {
        core.setScene(av[1]);
        core.buildScene();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    core.run();
    return 0;
}
