#pragma once
#pragma once

#include <Core/Trivial.hpp>
#include <Sc/WindowAPI.hpp>

namespace Sx
{
    class Cursor;

    class MeasureLine
    {
    public:
        MeasureLine(
            Sc::Font const &,
            Core::Color const &);
        void update(
            Sc::IDraw &draw,
            Core::Point const &cursor,
            bool isMouseLeftHeld);

    private:
        Sc::Font m_font;
        Core::Color m_color;

        bool m_isMeasuring;
        Core::Point m_start;
    };

    class MeasureGrid
    {
    public:
        MeasureGrid(
            float const size,
            float const repeat,
            Core::Color const &color);
        void update(Sc::IDraw &draw);

    private:
        float m_size;
        float m_repeat;
        Core::Color m_color;
    };
} // namespace Sx