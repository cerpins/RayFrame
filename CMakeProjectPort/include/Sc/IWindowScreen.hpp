#pragma once

namespace Sc
{
    struct IScreen;
    struct IWindowControl;
    struct WindowAPI;

    /*  All WindowAPI calls have an effect on the window,
        but not in a way that other WindowAPI callers would be
        affected.
    */

    struct IWindowScreen
    {
        virtual ~IWindowScreen() {}
        // All WindowAPI calls are side-effects
        virtual void start(IWindowControl &, WindowAPI &) = 0;
    };

} // namespace Sc