#pragma once

#include <string>
#include <Core/Trivial.hpp>

namespace Core
{
    struct Rectangle;
} // namespace Core

namespace Sc
{
    struct IDraw;
    struct Font;
    struct Texture;
} // namespace Sc

namespace Sx
{
    Core::Color constexpr g_drawDefaultColor = Core::g_colorBlack;
    Core::Color constexpr g_drawDefaultTint = Core::g_colorWhite;
    float constexpr g_drawDefaultThick = 5;

    void drawFont(
        Sc::IDraw &draw,
        int const z,
        Sc::Font const &font,
        std::string const &text,
        Core::Point const &point,
        float const size,
        float const spacing,
        Core::Color const &color = g_drawDefaultColor);
    void drawFontBasic(
        Sc::IDraw &draw,
        int const z,
        Sc::Font const &font,
        std::string const &text,
        Core::Point const &point,
        Core::Color const &color = g_drawDefaultColor);

    void drawFontBox(
        Sc::IDraw &draw,
        int const z,
        Sc::Font const &font, std::string const &text,
        Core::Rectangle const &bounds,
        float const size, float const spacing, bool const wordWrap,
        Core::Color const &color = g_drawDefaultColor);
    void drawFontBoxBasic(
        Sc::IDraw &draw,
        int const z,
        Sc::Font const &font, std::string const &text,
        Core::Rectangle const &bounds,
        Core::Color const &color = g_drawDefaultColor);

    void drawTexture(
        Sc::IDraw &draw,
        int const z,
        Sc::Texture const &texture,
        Core::Rectangle const &from, Core::Rectangle const &to,
        Core::Point const &origin, float const degrees,
        Core::Color const &tint = g_drawDefaultTint);
    void drawTextureBasic(
        Sc::IDraw &draw,
        int const z,
        Sc::Texture const &texture,
        Core::Point const &point,
        Core::Color const &tint = g_drawDefaultTint);
    void drawTextureOrigin(
        Sc::IDraw &draw,
        int const z,
        Sc::Texture const &texture,
        Core::Point const &point, Core::Point const &origin,
        Core::Color const &tint = g_drawDefaultTint);

    void drawLine(
        Sc::IDraw &draw,
        int const z,
        Core::Line const &line,
        float const thick = g_drawDefaultThick,
        Core::Color const &color = g_drawDefaultColor);
    void drawTriangle(
        Sc::IDraw &draw,
        int const z,
        Core::Tri const &triangle,
        Core::Color const &color = g_drawDefaultColor);

    // Needs implementation
    void drawLineRectangle(
        Sc::IDraw &draw,
        int const z,
        Core::Rectangle const &rectangle,
        Core::Point const &origin, float const degrees,
        float const thick = g_drawDefaultThick,
        Core::Color const &color = g_drawDefaultColor);

    void drawRectangle(
        Sc::IDraw &draw,
        int const z,
        Core::Rectangle const &rectangle,
        Core::Point const &origin, float const degrees,
        Core::Color const &color = g_drawDefaultColor);
    void drawRectangleBasic(
        Sc::IDraw &draw,
        int const z,
        Core::Rectangle const &rectangle,
        Core::Color const &color = g_drawDefaultColor);

} // namespace Sx