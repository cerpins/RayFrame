#pragma once

#include <Core/Aliases.hpp>

namespace Sc
{
    struct IWindowScreen;

    struct IWindowControl
    {
        virtual ~IWindowControl(){};
        virtual bool tickFrame() = 0;
        virtual void swapScreen(UP<IWindowScreen> nextScreen) = 0;
    };
} // namespace Sc