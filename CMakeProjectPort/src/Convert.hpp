#pragma once

#include <Core/Utility.hpp>

struct Vector2;
struct Rectangle;
struct Color;

namespace Core
{
    struct Point;
    struct Size;
    struct Rectangle;
    struct Color;
} // namespace Core

namespace Sc::Internal
{
    // Conversion
    inline Vector2 rlibConvertPoint(const Core::Point &point)
    {
        return {point.x, point.y};
    }
    inline Rectangle rlibConvertRectangle(const Core::Rectangle &rectangle)
    {
        return {
            rectangle.point.x, rectangle.point.y,
            rectangle.size.width, rectangle.size.height};
    }
    inline Color rlibConvertColor(const Core::Color &color)
    {
        return {color.r, color.g, color.b, color.a};
    }
} // namespace Sc::Internal