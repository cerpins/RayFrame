#pragma once

#include <raylib.h>

#include <Sc/API/IMouse.hpp>
#include <Core/Trivial.hpp>

namespace Sc::Internal
{
    struct IMouseControl : public IMouse
    {
        virtual ~IMouseControl(){};
        virtual void update() = 0;
        virtual void UpdateScreenSize(Core::Size size) = 0;
    };

    class Mouse : public IMouseControl
    {
        // Should turn this into an interface
    public:
        Mouse();
        // Inherits from IMouse
        virtual Core::Point delta() const override;
        virtual bool isClicked(EMouseButton) const override;
        virtual bool isHeld(EMouseButton) const override;
        virtual bool isReleased(EMouseButton) const override;
        virtual float wheelDelta() const override;
        // For use by implementation / context
        virtual void update() override;
        virtual void UpdateScreenSize(Core::Size size) override;

    private:
        Core::Size m_screenSize;

        Core::Point m_mouseLast;
        Core::Point m_mouseCurrent;

        Core::Point m_cursorLast;
        Core::Point m_cursorCurrent;
    };

    ::MouseButton ScConvertMouseButton(EMouseButton);
} // namespace Sc::Internal