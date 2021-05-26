#include <Gameplay/Screen.hpp>

#include <Sc/IWindowControl.hpp>
#include <Sc/WindowAPI.hpp>
#include <Sx/Draw.hpp>
#include <Gameplay/ScreenSwitch.hpp>

using ScreenTest = Gameplay::ScreenTest;

// Is ran every time we switch to this scene again
void ScreenTest::start(Sc::IWindowControl &control, Sc::WindowAPI &api)
{
    Sc::Font font = api.asset.loadFont("font/Hack-Regular.ttf", 25);

    /*  Can declare here instead of having to create class and doing some weird
        constructor initialization.
        (nice because game state tends to end up with a lot of variables) */

    while (control.tickFrame())
    {
        Sx::drawFontBasic(
            api, 100, font,
            "Hello, World!",
            {200, 200}, Core::g_colorBlack);

        Gameplay::screenSwitch(control, api);
    }

    /*  RAII cleans up anything instantiated beforehand.
        Also the context in which the screens exists is cleaned up after
        all scenes close, clearing up game resources and etc. */
}