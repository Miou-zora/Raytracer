/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** test_frame
*/

#include <criterion/criterion.h>

#include "Frame.hpp"

Test(frame, casual)
{
    RayTracer::Frame frame(100, 100);

    cr_assert(frame.getWidth() == 100);
    cr_assert(frame.getHeight() == 100);
}

Test(frame, setPixel)
{
    RayTracer::Frame frame(100, 100);

    frame.setPixel(std::make_pair(0, 0), RayTracer::RGBAColor(255, 255, 255));
    cr_assert(frame.getPixel(std::make_pair(0, 0)) == RayTracer::RGBAColor(255, 255, 255));
}
