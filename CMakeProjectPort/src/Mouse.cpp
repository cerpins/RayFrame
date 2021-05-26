#include "Mouse.hpp"

#include <cmath>

#include <Core/Trivial.hpp>
#include <Core/Invariant.hpp>
#include <Core/Utility.hpp>

using Mouse = Sc::Internal::Mouse;

Mouse::Mouse()
    : m_screenSize{0, 0},

      m_mouseLast{0, 0},
      m_mouseCurrent{0, 0}
{
}
Core::Point Mouse::delta() const
{
    return m_mouseCurrent - m_mouseLast;
}
bool Mouse::isHeld(EMouseButton button) const
{
    return ::IsMouseButtonDown(ScConvertMouseButton(button));
}
bool Mouse::isClicked(EMouseButton button) const
{
    return ::IsMouseButtonPressed(ScConvertMouseButton(button));
}
bool Mouse::isReleased(EMouseButton button) const
{
    return ::IsMouseButtonReleased(ScConvertMouseButton(button));
}
float Mouse::wheelDelta() const
{
    return static_cast<float>(::GetMouseWheelMove());
}
void Mouse::update()
{
    Vector2 point = ::GetMousePosition();
    m_mouseLast = m_mouseCurrent;
    m_mouseCurrent = {point.x, point.y};
}
void Mouse::UpdateScreenSize(Core::Size size)
{
    m_screenSize = size;
}

::MouseButton Sc::Internal::ScConvertMouseButton(EMouseButton button)
{
    switch (button)
    {
    case EMouseButton::Left:
        return ::MOUSE_LEFT_BUTTON;
    case EMouseButton::Middle:
        return ::MOUSE_MIDDLE_BUTTON;
    default:
        return ::MOUSE_RIGHT_BUTTON;
    }
}