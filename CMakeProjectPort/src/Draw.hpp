#pragma once

#include <map>
#include <queue>

#include <Core/Aliases.hpp>
#include <Sc/API/IAsset.hpp>
#include <Sc/API/IDraw.hpp>
#include "Asset.hpp"

#include "IDrawObject.hpp"
#include "DrawObject.hpp"

namespace Sc::Internal
{
    struct IDrawControl : public IDraw
    {
        virtual ~IDrawControl(){};
        virtual void inOrderOfZ() = 0;
    };

    class Draw : public IDrawControl
    {
    public:
        Draw(IAssetControl &asset);

        // Inherited from IDraw
        virtual void font(ArgsFont const &) override;
        virtual void fontBox(ArgsFontBox const &) override;
        virtual void texture(ArgsTexture const &) override;
        virtual void line(ArgsLine const &) override;
        virtual void triangle(ArgsTriangle const &) override;
        virtual void rectangle(ArgsRectangle const &) override;

        virtual void inOrderOfZ() override;

    private:
        template <class TScArgs>
        void emplace(TScArgs const &draw)
        {
            m_draws[draw.args.z].emplace(
                std::make_unique<DrawObject<TScArgs>>(draw));
        }

        IAssetControl &m_asset;

        // It would be faster to use (map<int, queue>) !!!
        std::map<int, std::queue<UP<IDrawObject>>> m_draws;
    };
} // namespace Sc::Internal