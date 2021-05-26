#include <Core/Utility.hpp>

#include <cmath>
#include <array>

#include <Core/Invariant.hpp>
#include <Core/Trivial.hpp>
#include <Core/Degrees.hpp>

using namespace Core;

void Core::log(const std::string &origin, const std::vector<std::string> &msgs)
{
    size_t totalMsgs = msgs.size();
    std::cout << "[" << origin << "]" << std::endl;
    for (size_t i = 0; i < totalMsgs; i++)
    {
        std::cout << msgs[i] << std::endl;
    }
}

float Core::degreesAsRadians(float degrees)
{
    const static float PI = 3.1415f;
    return degrees * (PI / 180.f);
}

Point Core::pointRotated(const Point &point, float degrees, const Point &absOrigin)
{
    float radians = degreesAsRadians(degrees);
    Point pointFromOrigin = point - absOrigin;
    Point pointFromOriginRotated = {
        pointFromOrigin.x * std::cos(radians) - pointFromOrigin.y * std::sin(radians),
        pointFromOrigin.x * std::sin(radians) + pointFromOrigin.y * std::cos(radians)};

    return pointFromOriginRotated + absOrigin;
}
Color Core::colorRainbow()
{
    int r = std::rand() % 7;
    switch (r)
    {
    case 0:
        return Core::colorNormal(0.4f, 0.f, 1.f);
    case 1:
        return Core::colorNormal(0.f, 0.f, 1.f);
    case 2:
        return Core::colorNormal(0.5f, 0.5f, 1.f);
    case 3:
        return Core::colorNormal(0.f, 1.f, 0.f);
    case 4:
        return Core::colorNormal(1.f, 0.f, 1.f);
    case 5:
        return Core::colorNormal(1.f, 0.6f, 0.6f);
    default:
        return Core::colorNormal(1.f, 0.f, 0.f);
    }
}
// Multiplty RGBA values of color
Color Core::colorMultiplyRGBA(
    Color const &color,
    std::array<float, 4> const &multipliers)
{
    return {
        static_cast<unsigned char>(clamp(static_cast<float>(color.r) * multipliers[0], {0, 255})),
        static_cast<unsigned char>(clamp(static_cast<float>(color.g) * multipliers[1], {0, 255})),
        static_cast<unsigned char>(clamp(static_cast<float>(color.b) * multipliers[2], {0, 255})),
        static_cast<unsigned char>(clamp(static_cast<float>(color.a) * multipliers[3], {0, 255})),
    };
}
// Multiply RGB values of color
// Should be moved into scope of Color
Color Core::colorMultiplyRGB(
    Color const &color,
    float const multiplier)
{
    return colorMultiplyRGBA(color, {multiplier, multiplier, multiplier, 1});
}
// Multiply Alpha value of color
Color Core::colorMultiplyA(
    Color const &color,
    float const multiplier)
{
    return colorMultiplyRGBA(color, {1, 1, 1, multiplier});
}

Rectangle Core::marginToRectangle(
    Rectangle const &rectangle,
    float const margin)
{
    return {
        Point{
            rectangle.point.x + margin,
            rectangle.point.y + margin},
        Size{
            rectangle.size.width - margin,
            rectangle.size.height - margin}};
}
float Core::clamp(float const value, Range const &range)
{
    return std::min(range.max(), std::max(range.min(), value));
}

float Core::repeat(float const value, Range const &range)
{
    bool inRange = value >= range.min() && value <= range.max();
    if (inRange)
    {
        return value;
    }
    bool strictRange = range.min() == range.max();
    if (strictRange)
    {
        return range.min();
    }

    float offset = range.max() - range.min();
    float left = value - range.min();
    float leftOffset = left / offset;
    float noDecimal = leftOffset - std::trunc(leftOffset);
    noDecimal = noDecimal < 0 ? noDecimal + 1 : noDecimal;
    float overflow = noDecimal * offset;
    overflow += range.min();

    return overflow;
}

bool Core::isPointIn(Point const &p, Rectangle const &rect)
{
    return (
        p.x > rect.point.x &&
        p.y > rect.point.y &&
        p.x < rect.point.x + rect.size.width &&
        p.y < rect.point.y + rect.size.height);
}

Point Core::offsetFromRotational(Point const &offset, Core::RotationalPoint const &rotational)
{
    return pointRotated(offset + rotational.m_point, rotational.m_degrees.value(), rotational.m_point);
}
Point Core::pointFromRotational(Point const &point, Core::RotationalPoint const &rotational)
{
    // pointRotated()
    return pointRotated(point, rotational.m_degrees.value(), rotational.m_point);
    // return pointRotated()
}
#include <iostream>
Normal Core::transformLinearUpDown(Normal const &x)
{
    float const y = (x > 0.5f ? 1.f - x : x) * 2;
    return Normal{y};
}
Normal Core::transformLinearUpDownInvert(Normal const &x)
{
    return Normal{1.f - transformLinearUpDown(x)};
}
Normal Core::transformExponent(Normal const &x, float const exponent)
{
    float const y = std::pow(x, exponent);
    return Normal{y};
}
Normal Core::transformSqrt(Normal const &x)
{
    float const y = std::sqrt(x);
    return Normal{y};
}
Normal Core::transformSqrtInOut(Normal const &x)
{
    float const y =
        x < 0.5f ? std::sqrt(x * 2) : std::sqrt((1.f - x) * 2);
    return Normal{y};
}
Normal Core::transformSqrtUpDown(Normal const &x)
{
    float const y =
        x < 0.5f ? std::sqrt(x * 2.f) : std::sqrt((1.f - x) * 2.f);
    return Normal{y};
}
Point Core::centerOf(Rectangle const &rectangle)
{
    return {
        rectangle.point.x + rectangle.size.width / 2,
        rectangle.point.y + rectangle.size.height / 2};
}