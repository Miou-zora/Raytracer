/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** tests_ppmdisplayer
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "PPMDisplayer.hpp"
#include "Frame.hpp"

Test(ppmdisplayer, casual)
{
    RayTracer::Frame frame(2, 2);
    RayTracer::PPMDisplayer displayer;

    frame.setPixel(std::make_pair(0, 0), RayTracer::RGBAColor(255, 0, 255));
    frame.setPixel(std::make_pair(0, 1), RayTracer::RGBAColor(255, 255, 0));
    frame.setPixel(std::make_pair(1, 0), RayTracer::RGBAColor(0, 255, 255));
    frame.setPixel(std::make_pair(1, 1), RayTracer::RGBAColor(255, 255, 255));
    cr_redirect_stdout();
    displayer.display(frame);
    cr_assert_stdout_eq_str("P3\n"
                            "2 2\n"
                            "255\n"
                            "255 0 255\n"
                            "255 255 0\n"
                            "0 255 255\n"
                            "255 255 255\n");
}

Test(ppmdisplayer, casual2)
{
    RayTracer::Frame frame(2, 2);
    RayTracer::PPMDisplayer displayer;

    frame.setPixel(std::make_pair(0, 0), RayTracer::RGBAColor(0, 0, 0));
    frame.setPixel(std::make_pair(0, 1), RayTracer::RGBAColor(0, 0, 0));
    frame.setPixel(std::make_pair(1, 0), RayTracer::RGBAColor(0, 0, 0));
    frame.setPixel(std::make_pair(1, 1), RayTracer::RGBAColor(0, 0, 0));
    cr_redirect_stdout();
    displayer.display(frame);
    cr_assert_stdout_eq_str("P3\n"
                            "2 2\n"
                            "255\n"
                            "0 0 0\n"
                            "0 0 0\n"
                            "0 0 0\n"
                            "0 0 0\n");
}
