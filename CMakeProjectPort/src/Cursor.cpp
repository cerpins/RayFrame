#include <Sx/Cursor.hpp>

#include <Core/Utility.hpp>
#include <Sc/API/IMouse.hpp>

using Cursor = Sx::Cursor;

Cursor::Cursor(
    Core::Bound const &horizontal,
    Core::Bound const &vertical)
    : m_horizontal(horizontal),
      m_vertical(vertical),
      m_point{
          Core::extent(m_horizontal) / 2,
          Core::extent(m_vertical) / 2} {}

void Cursor::update(Sc::IMouse &mouse)
{
    if (m_isLocked)
    {
        return;
    }

    Core::Point const delta = mouse.delta();
    m_point = {
        Core::clamp(m_point.x + delta.x, m_horizontal),
        Core::clamp(m_point.y + delta.y, m_vertical)};
}
Core::Point Cursor::point() const
{
    return m_point;
}
void Cursor::lock()
{
    m_isLocked = true;
}
void Cursor::unlock()
{
    m_isLocked = false;
}