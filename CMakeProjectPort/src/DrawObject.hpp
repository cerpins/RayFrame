#pragma once

#include <iostream>
#include <raylib.h>

#include <Core/Utility.hpp>
#include <Sc/API/IDraw.hpp>
#include "Convert.hpp"

namespace Sc::Internal
{
    struct ScArgsFont
    {
        ArgsFont const args;
        ::Font const font;
        void Draw()
        {
            ::DrawTextEx(
                font,
                args.text.c_str(),
                rlibConvertPoint(args.point),
                args.size,
                args.spacing,
                rlibConvertColor(args.color));
        }
    };
    struct ScArgsFontBox
    {
        ArgsFontBox const args;
        ::Font const font;
        void Draw()
        {
            ::DrawTextRec(
                font,
                args.text.c_str(),
                rlibConvertRectangle(args.rectangle),
                args.size,
                args.spacing,
                args.wordWrap,
                rlibConvertColor(args.tint));
        }
    };

    struct ScArgsTexture
    {
        ArgsTexture const args;
        ::Texture const tex;
        void Draw()
        {
            ::DrawTexturePro(
                tex,
                rlibConvertRectangle(args.from),
                rlibConvertRectangle(args.to),
                rlibConvertPoint(args.origin),
                args.degrees,
                rlibConvertColor(args.tint));
        }
    };

    struct ScArgsLine
    {
        ArgsLine const args;
        void Draw()
        {
            ::DrawLineEx(
                rlibConvertPoint(args.start),
                rlibConvertPoint(args.end),
                args.thick,
                rlibConvertColor(args.color));
        }
    };
    struct ScArgsTriangle
    {
        ArgsTriangle const args;
        void Draw()
        {
            ::DrawTriangle(
                rlibConvertPoint(args.triangle.first),
                rlibConvertPoint(args.triangle.second),
                rlibConvertPoint(args.triangle.third),
                rlibConvertColor(args.color));
        }
    };
    struct ScArgsRectangle
    {
        ArgsRectangle const args;
        void Draw()
        {
            ::DrawRectanglePro(
                rlibConvertRectangle(args.rectangle),
                rlibConvertPoint(args.origin),
                args.degrees,
                rlibConvertColor(args.color));
        }
    };

    // Adapt to IDrawObject interface
    template <class TDrawArgs>
    struct DrawObject : public IDrawObject
    {
        DrawObject(TDrawArgs const &args) : m_args(args) {}
        TDrawArgs m_args;
        virtual void Draw() override
        {
            m_args.Draw();
        }
    };
} // namespace Sc::Internal