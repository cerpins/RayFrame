#pragma once

#include <string>

#include <Core/Trivial.hpp>
#include <Sc/API/IAsset.hpp>

namespace Sc
{
    struct ArgsFont;
    struct ArgsFontBox;
    struct ArgsTexture;
    struct ArgsLine;
    struct ArgsTriangle;
    struct ArgsRectangle;

    struct IDraw
    {
        virtual ~IDraw(){};

        virtual void font(ArgsFont const &) = 0;
        virtual void fontBox(ArgsFontBox const &) = 0;
        virtual void texture(ArgsTexture const &) = 0;
        virtual void line(ArgsLine const &) = 0;
        virtual void triangle(ArgsTriangle const &) = 0;
        virtual void rectangle(ArgsRectangle const &) = 0;
    };

    struct ArgsFont
    {
        int const z;
        Sc::Font const font;
        std::string const text;
        Core::Point const point;
        float const size;
        float const spacing;
        Core::Color const color;
    };

    struct ArgsFontBox
    {
        int const z;
        Sc::Font const font;
        std::string const text;
        Core::Rectangle const rectangle;
        float const size;
        float const spacing;
        bool const wordWrap;
        Core::Color const tint;
    };

    struct ArgsTexture
    {
        int const z;
        Sc::Texture const texture;
        Core::Rectangle const from;
        Core::Rectangle const to;
        Core::Point const origin;
        float const degrees;
        Core::Color const tint;
    };

    struct ArgsLine
    {
        int const z;
        Core::Point const start;
        Core::Point const end;
        float const thick;
        Core::Color const color;
    };

    struct ArgsTriangle
    {
        int const z;
        Core::Tri const triangle;
        Core::Color const color;
    };

    struct ArgsRectangle
    {
        int const z;
        Core::Rectangle const rectangle;
        Core::Point const origin;
        float const degrees;
        Core::Color const color;
    };
} // namespace Sc