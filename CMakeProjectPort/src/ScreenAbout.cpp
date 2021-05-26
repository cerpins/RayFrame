#include <Gameplay/Screen.hpp>

#include <iostream>

#include <raylib.h>
#include <chrono>

#include <Core/Aliases.hpp>
#include <Core/Trivial.hpp>
#include <Core/Slider.hpp>
#include <Sc/WindowAPI.hpp>

#include <Sx/Draw.hpp>
#include <Gameplay/ScreenSwitch.hpp>

using ScreenAbout = Gameplay::ScreenAbout;

void ScreenAbout::start(Sc::IWindowControl &control, Sc::WindowAPI &api)
{
    std::cout << "Screen about." << std::endl;

    float i = 0;
    while (control.tickFrame())
    {
        i++;

        Sx::drawRectangle(
            api, 0,
            {200, 200, 80, 100},
            {40, 50}, i);


        Sx::drawLine(
            api, 0,
            {{800, 600}, {0, 600}}, 5, Core::g_colorMint);

        Gameplay::screenSwitch(control, api);
    }
}
