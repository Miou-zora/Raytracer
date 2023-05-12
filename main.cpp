/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include "SFMLCore.hpp"

int main(int ac, char **av)
{
    RayTracer::SFMLCore core(1920, 1080);
    if (ac != 2)
        return 84;
    core.setScene(av[1]);
    core.buildScene();
    core.run();
    return 0;
}
