/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include "BasicCore.hpp"

int main(int ac, char **av)
{
    RayTracer::BasicCore core;
    if (ac != 2)
        return 84;
    core.setScene(av[1]);
    core.buildScene();
    core.run();
    return 0;
}
