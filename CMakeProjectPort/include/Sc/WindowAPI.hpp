#pragma once

#include <string>
#include <Core/Trivial.hpp>

#include <Sc/API/IAsset.hpp>
#include <Sc/API/IDraw.hpp>
#include <Sc/API/IMouse.hpp>
#include <Sc/API/IKeyboard.hpp>

namespace Sc
{
    /*  Implicitly convertible to any of the WindowAPI sub-interfaces.
    */
    struct WindowAPI
    {
        IAsset &asset;
        IDraw &draw;
        IMouse &mouse;
        IKeyboard &keyboard;

        operator IAsset &()
        {
            return asset;
        }
        operator IDraw &()
        {
            return draw;
        }
        operator IMouse &()
        {
            return mouse;
        }
        operator IKeyboard &()
        {
            return keyboard;
        }
    };

} // namespace Sc