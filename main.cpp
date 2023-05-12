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
    core.build(av[1]);
    core.run();
    return 0;
}
