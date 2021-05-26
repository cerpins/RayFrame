#pragma once

namespace Core
{
    struct Point;
}

namespace Sc
{
    enum class EMouseButton;

    struct IMouse
    {
        virtual ~IMouse(){};
        virtual Core::Point delta() const = 0;
        virtual bool isClicked(EMouseButton) const = 0;
        virtual bool isHeld(EMouseButton) const = 0;
        virtual bool isReleased(EMouseButton) const = 0;
        virtual float wheelDelta() const = 0;
    };

    enum class EMouseButton
    {
        Left,
        Middle,
        Right
    };
} // namespace Sc