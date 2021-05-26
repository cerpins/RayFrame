#include "DrawExtended.hpp"

#include "Asset.hpp"
#include "Draw.hpp"

/*
using DrawExtended = Sc::Internal::DrawExtended;

// This probably sucks for performance,
// think about that later.
DrawExtended::DrawExtended(IAssetControl &asset)
    : m_draw(asset) {}

void DrawExtended::font(
    int const z,
    Sc::Font const &font,
    std::string const &text,
    Core::Rectangle const &rectangle,
    float const size,
    float const spacing,
    bool const wordWrap,
    Core::Color const &tint)
{
    m_draw.font(
        {z,
         font, text,
         rectangle,
         size, spacing, wordWrap,
         tint});
}
void DrawExtended::fontBasic(
    int const z,
    Sc::Font const &font,
    std::string const &text,
    Core::Rectangle const &rectangle,
    Core::Color const &color)
{
    m_draw.font(
        {z,
         font, text,
         rectangle,
         font.scale, 0, true,
         color});
}

void DrawExtended::texture(
    int const z,
    Sc::Texture const &texture,
    Core::Rectangle const &from,
    Core::Rectangle const &to,
    Core::Point const &origin,
    float const degrees,
    Core::Color const &tint)
{
    m_draw.texture({z, texture, from, to, origin, degrees, tint});
}
void DrawExtended::textureBasic(
    int const z,
    Sc::Texture const &texture,
    Core::Point const &point,
    Core::Color const &tint)
{
    m_draw.texture(
        {z,
         texture,
         {{0, 0}, texture.size},
         {point, texture.size},
         {0, 0},
         0,
         tint});
}

// Inherited from IDraw
void DrawExtended::line(
    int const z,
    Core::Point const &start,
    Core::Point const &end,
    float const thick,
    Core::Color const &color)
{
    m_draw.line({z, start, end, thick, color});
}
void DrawExtended::lineRectangle(
    int const z,
    Core::Rectangle const &rectangle,
    Core::Point const &origin,
    float const degrees,
    float const,
    Core::Color const &color)
{
    m_draw.rectangle({z, rectangle, origin, degrees, color});
}
void DrawExtended::lineRectangleBasic(
    int const z,
    Core::Rectangle const &rectangle,
    Core::Color const &color)
{
    m_draw.rectangle(
        {z,
         rectangle,
         {0, 0},
         0,
         color});
}

// Inherited from IDraw
void DrawExtended::rectangle(
    int const z,
    Core::Rectangle const &rectangle,
    Core::Point const &origin,
    float const degrees,
    Core::Color const &color)
{
    m_draw.rectangle({z, rectangle, origin, degrees, color});
}
void DrawExtended::rectangleBasic(
    int const z,
    Core::Rectangle const &rectangle,
    Core::Color const &color)
{
    m_draw.rectangle(
        {z,
         rectangle,
         {0, 0},
         0,
         color});
}

void DrawExtended::inOrderOfZ()
{
    m_draw.inOrderOfZ();
}
*/