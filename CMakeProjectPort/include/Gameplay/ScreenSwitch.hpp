#pragma once

#include <iostream>
#include <Sc/IWindowControl.hpp>
#include <Gameplay/Screen.hpp>

namespace Gameplay
{
    void inline screenSwitch(Sc::IWindowControl &control, Sc::WindowAPI &api)
    {
        switch (api.keyboard.key())
        {
        case Sc::EKeyboardKey::One:
            control.swapScreen(std::make_unique<Gameplay::ScreenTitle>());
            break;
        case Sc::EKeyboardKey::Two:
            control.swapScreen(std::make_unique<Gameplay::ScreenAbout>());
            break;
        case Sc::EKeyboardKey::Three:
            control.swapScreen(std::make_unique<Gameplay::ScreenTest>());
            break;
        default:
            break;
        };
    }
} // namespace Gameplay