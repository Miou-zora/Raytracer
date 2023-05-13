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

    core.init();
    if (ac != 2)
        return 84;
    try {
        core.setScenePath(av[1]);
        core.buildScene();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    core.run();
    return 0;
}
