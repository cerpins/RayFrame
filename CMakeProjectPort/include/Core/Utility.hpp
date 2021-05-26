#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>

namespace Core
{
    struct Point;
    struct RotationalPoint;
    struct Rectangle;
    class Range;
    struct Color;
    class Normal;

    // Don't use
    void log(
        const std::string &origin,
        std::vector<std::string> const &msgs = {});

    float degreesAsRadians(float degrees);
    Point pointRotated(
        Point const &point,
        float degrees,
        Point const &origin); // move into pointf

    Color colorRainbow();
    // Multiplty RGBA values of color
    Color colorMultiplyRGBA(
        Color const &color,
        std::array<float, 4> const &multipliers);
    // Multiply RGB values of color
    Color colorMultiplyRGB(
        Color const &color,
        float const multiplier);
    // Multiply Alpha value of color
    Color colorMultiplyA(
        Color const &color,
        float const multiplier);

    Rectangle marginToRectangle(
        Rectangle const &rectangle,
        float const margin);

    float clamp(float value, Range const &range);
    // Like clamp but loop back exceeding value
    float repeat(float value, Range const &range);

    // Collision
    bool isPointIn(Point const &, Rectangle const &);

    Point offsetFromRotational(Point const &, Core::RotationalPoint const &);
    Point pointFromRotational(Point const &, RotationalPoint const &);

    // Transform functions
    // Up/Down(Invert)= Value bounces
    // In/Out(Invert) = Function is applied at beginning and end
    Normal transformLinearUpDown(Normal const &x);
    Normal transformLinearUpDownInvert(Normal const &x);
    Normal transformExponent(Normal const &x, float const exponent);
    Normal transformSqrt(Normal const &x);
    Normal transformSqrtInOut(Normal const &x);
    Normal transformSqrtUpDown(Normal const &x);

    Point centerOf(Rectangle const &);
} // namespace Core
