#pragma once

#include <Sc/IWindowScreen.hpp>

namespace Gameplay
{
    /*  Screens need to know about every single other screen,
        thus single .hpp file. 
    */

    struct ScreenTitle : public Sc::IWindowScreen
    {
        void start(Sc::IWindowControl &control, Sc::WindowAPI &api) override;
    };
    struct ScreenAbout : public Sc::IWindowScreen
    {
        void start(Sc::IWindowControl &control, Sc::WindowAPI &api) override;
    };
    struct ScreenTest : public Sc::IWindowScreen
    {
        void start(Sc::IWindowControl &control, Sc::WindowAPI &api) override;
    };
} // namespace Gameplay