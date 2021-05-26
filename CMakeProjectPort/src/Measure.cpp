#include <Sx/Measure.hpp>

#include <string>
#include <Core/Utility.hpp>
#include <Sx/Draw.hpp>

using MeasureLine = Sx::MeasureLine;
using MeasureGrid = Sx::MeasureGrid;

MeasureLine::MeasureLine(
    Sc::Font const &font,
    Core::Color const &color)
    : m_font(font),
      m_color(color),

      m_isMeasuring(false),
      m_start{0, 0}
{
}
void MeasureLine::update(
    Sc::IDraw &draw,
    Core::Point const &cursor,
    bool isMouseLeftHeld)
{
    if (!m_isMeasuring &&
        isMouseLeftHeld)
    {
        m_isMeasuring = true;
        m_start = cursor;
    }
    else if (
        m_isMeasuring &&
        isMouseLeftHeld)
    {
        std::string textStart =
            "x:" + std::to_string(m_start.x) +
            "\t" +
            "y:" + std::to_string(m_start.y);

        Core::Point delta = cursor - m_start;
        std::string textDelta =
            "x:" + std::to_string(delta.x) +
            "\t" +
            "y:" + std::to_string(delta.y);

        Sx::drawLine(
            draw, 1000,
            {m_start, cursor},
            5, m_color);
        Sx::drawFontBasic(
            draw, 1001, m_font, textStart,
            m_start, m_color);
        Sx::drawFontBasic(
            draw, 1003, m_font, textDelta,
            cursor, m_color);
    }
    else
    {
        m_isMeasuring = false;
    }
}

#include <iostream>
MeasureGrid::MeasureGrid(
    float const size,
    float const repeat,
    Core::Color const &color)
    : m_size(size),
      m_repeat(repeat),
      m_color(color)
{
}
void MeasureGrid::update(Sc::IDraw &draw)
{
    for (float x = 0; x < m_repeat; x++)
    {
        for (float y = 0; y < m_repeat; y++)
        {
            float margin = 1;
            Sx::drawRectangleBasic(
                draw, -1000,
                {m_size * x + margin,
                 m_size * y + margin,
                 m_size - margin * 2,
                 m_size - margin * 2},
                m_color);
        }
    }
}