#pragma once

#include <Core/Trivial.hpp>
#include <Sc/API/IDraw.hpp>

#include "Draw.hpp"

namespace Sc::Internal
{
    /*
    // Adapter to Draw for richer interface
    class DrawExtended : public IDrawControl
    {
    public:
        DrawExtended(Internal::IAssetControl &asset);

        virtual void font(
            int const z,
            Sc::Font const &font,
            std::string const &text,
            Core::Rectangle const &rectangle,
            float const size,
            float const spacing,
            bool const wordWrap,
            Core::Color const &tint) override;
        virtual void fontBasic(
            int const z,
            Sc::Font const &font,
            std::string const &text,
            Core::Rectangle const &rectangle,
            Core::Color const &color) override;

        // Inherited from IDraw
        virtual void texture(
            int const z,
            Sc::Texture const &texture,
            Core::Rectangle const &from,
            Core::Rectangle const &to,
            Core::Point const &origin,
            float const degrees,
            Core::Color const &tint) override;
        virtual void textureBasic(
            int const z,
            Sc::Texture const &texture,
            Core::Point const &point,
            Core::Color const &tint) override;

        virtual void line(
            int const z,
            Core::Point const &start,
            Core::Point const &end,
            float const thick,
            Core::Color const &color) override;
        virtual void lineRectangle(
            int const z,
            Core::Rectangle const &rectangle,
            Core::Point const &origin,
            float const degrees,
            float const thick,
            Core::Color const &color) override;
        virtual void lineRectangleBasic(
            int const z,
            Core::Rectangle const &rectangle,
            Core::Color const &color) override;

        virtual void rectangle(
            int const z,
            Core::Rectangle const &rectangle,
            Core::Point const &origin,
            float const degrees,
            Core::Color const &color) override;
        virtual void rectangleBasic(
            int const z,
            Core::Rectangle const &rectangle,
            Core::Color const &color) override;

        virtual void inOrderOfZ() override;

    private:
        Draw m_draw;
    };
    */
} // namespace Sc::Internal