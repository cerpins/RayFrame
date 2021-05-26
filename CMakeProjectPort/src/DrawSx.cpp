#include <Sx/Draw.hpp>

#include <iostream>
#include <cmath>

#include <Core/Trivial.hpp>
#include <Sc/API/IDraw.hpp>
#include <Sc/API/IAsset.hpp>

void Sx::drawFont(
    Sc::IDraw &draw,
    int const z,
    Sc::Font const &font,
    std::string const &text,
    Core::Point const &point,
    float const size,
    float const spacing,
    Core::Color const &color)
{
    draw.font({z, font, text, point, size, spacing, color});
}
void Sx::drawFontBasic(
    Sc::IDraw &draw,
    int const z,
    Sc::Font const &font,
    std::string const &text,
    Core::Point const &point,
    Core::Color const &color)
{
    draw.font({z, font, text, point, font.size, 0, color});
}

void Sx::drawFontBox(
    Sc::IDraw &draw,
    int const z,
    Sc::Font const &font, std::string const &text,
    Core::Rectangle const &bounds,
    float const size, float const spacing, bool const wordWrap,
    Core::Color const &color)
{
    draw.fontBox(
        {z,
         font, text,
         bounds, size, spacing, wordWrap,
         color});
}
void Sx::drawFontBoxBasic(
    Sc::IDraw &draw,
    int const z,
    Sc::Font const &font, std::string const &text,
    Core::Rectangle const &bounds,
    Core::Color const &color)
{
    draw.fontBox(
        {z,
         font, text,
         bounds, font.size, 0, true,
         color});
}

void Sx::drawTexture(
    Sc::IDraw &draw,
    int const z,
    Sc::Texture const &texture,
    Core::Rectangle const &from, Core::Rectangle const &to,
    Core::Point const &origin, float const degrees,
    Core::Color const &tint)
{
    draw.texture(
        {z,
         texture, from, to,
         origin, degrees,
         tint});
}
void Sx::drawTextureBasic(
    Sc::IDraw &draw,
    int const z,
    Sc::Texture const &texture,
    Core::Point const &point,
    Core::Color const &tint)
{
    draw.texture(
        {z,
         texture,
         {{0, 0}, texture.size},
         {point, texture.size},
         {0, 0},
         0,
         tint});
}
void Sx::drawTextureOrigin(
    Sc::IDraw &draw,
    int const z,
    Sc::Texture const &texture,
    Core::Point const &point, Core::Point const &origin,
    Core::Color const &tint)
{
    draw.texture(
        {z,
         texture,
         {{0, 0}, texture.size},
         {point, texture.size},
         origin,
         0,
         tint});
}
void Sx::drawLine(
    Sc::IDraw &draw,
    int const z,
    Core::Line const &line, float const thick,
    Core::Color const &color)
{
    draw.line(
        {z,
         line.start, line.end,
         thick,
         color});
}

void Sx::drawTriangle(
    Sc::IDraw &draw,
    int const z,
    Core::Tri const &triangle,
    Core::Color const &color)
{
    // Very verbose... Can somehow do more simply?
    // Vertices have to be organized in counter-clockwise order
    Core::Point const triangleAverage =
        {
            (triangle.first.x + triangle.second.x + triangle.third.x) / 3,
            (triangle.first.y + triangle.second.y + triangle.third.y) / 3,
        };

    std::array<Core::Point, 3> points = {
        triangle.first, triangle.second, triangle.third};
    std::array<std::pair<float, size_t>, 3> angles;

    for (size_t i = 0; i < 3; i++)
    {
        Core::Point delta = points[i] - triangleAverage;
        angles[i] = {std::atan2(delta.x, delta.y), i};
    }

    if (angles[0].first > angles[1].first)
    {
        std::swap(angles[0], angles[1]);
    }
    if (angles[1].first > angles[2].first)
    {
        std::swap(angles[1], angles[2]);
    }
    if (angles[0].first > angles[1].first)
    {
        std::swap(angles[0], angles[1]);
    }

    draw.triangle(
        {z,
         {points[angles[0].second], points[angles[1].second], points[angles[2].second]},
         color});
}
// Unimplemented
void Sx::drawLineRectangle(
    Sc::IDraw &draw,
    int const z,
    Core::Rectangle const &rectangle,
    Core::Point const &origin, float const degrees,
    float const,
    Core::Color const &color)
{
    draw.rectangle(
        {z,
         rectangle,
         origin, degrees,
         //  thick,
         color});
}

void Sx::drawRectangle(
    Sc::IDraw &draw,
    int const z,
    Core::Rectangle const &rectangle,
    Core::Point const &origin, float const degrees,
    Core::Color const &color)
{
    draw.rectangle(
        {z,
         rectangle,
         origin, degrees,
         color});
}
void Sx::drawRectangleBasic(
    Sc::IDraw &draw,
    int const z,
    Core::Rectangle const &rectangle,
    Core::Color const &color)
{
    draw.rectangle(
        {z,
         rectangle,
         {0, 0},
         0,
         color});
}