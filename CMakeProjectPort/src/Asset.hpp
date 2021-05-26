#pragma once

#include <vector>
#include <raylib.h>

#include <Sc/API/IAsset.hpp>

namespace Sc::Internal
{
    // Sources
    struct InfoTexture
    {
        std::string const pathAndName;
        ETextureMod const mod;
        bool operator==(InfoTexture const &) const;
    };
    struct InfoFont
    {
        std::string const pathAndName;
        float const size;
        bool operator==(InfoFont const &) const;
    };

    // Anti-ray layer on assets
    struct IAssetControl : public IAsset
    {
        virtual ~IAssetControl(){};
        virtual ::Texture lookupTexture(Sc::Texture const &) = 0;
        virtual ::Font lookupFont(Sc::Font const &) = 0;
    };

    class Asset : public IAssetControl
    {
    public:
        // Release everything
        virtual ~Asset();

        // Inherited from IAsset
        virtual Sc::Texture loadTexture(
            std::string const &pathAndName,
            ETextureMod const mod) override;

        virtual Font loadFont(
            std::string const &pathAndName,
            float const size) override;
        // Inherited from IAssetControl
        virtual ::Font lookupFont(Sc::Font const &) override;
        virtual ::Texture lookupTexture(Sc::Texture const &) override;

    private:
        std::string const m_assetRoot = "./asset/";

        std::vector<std::pair<InfoTexture, ::Texture>> m_textures;
        std::vector<std::pair<InfoFont, ::Font>> m_fonts;
    };
} // namespace Sc::Internal