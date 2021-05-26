#pragma once

#include <string>
#include <Core/Trivial.hpp>

namespace Sc
{
    struct Texture;
    struct Font;

    enum class ETextureMod
    {
        None,
        MirrorHorizontal
    };

    struct IAsset
    {
        virtual ~IAsset() {}

        virtual Texture loadTexture(
            std::string const &pathAndName,
            ETextureMod const mod = ETextureMod::None) = 0;
        // Fonts are rasterized at scale on load
        virtual Font loadFont(
            std::string const &pathAndName,
            float const size) = 0;
    };

    // Make members non-reassignable
    struct Texture
    {
        size_t id;
        Core::Size size;
    };

    struct Font
    {
        size_t id;
        float size;
    };
} // namespace Sc