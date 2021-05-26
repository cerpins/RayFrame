#pragma once

namespace Sc::Internal
{
    struct IDrawObject
    {
        virtual ~IDrawObject() {}
        virtual void Draw() = 0;
    };
} // namespace Sc::Internal