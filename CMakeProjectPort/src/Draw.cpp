#include "Draw.hpp"

#include <algorithm>
#include <iostream>

#include <raylib.h>

#include "Convert.hpp"

using InfoTexture = Sc::Internal::InfoTexture;
using InfoFont = Sc::Internal::InfoFont;
using Draw = Sc::Internal::Draw;

Draw::Draw(IAssetControl &asset)
    : m_asset(asset) {}

// Can implement forwarding here?
void Draw::font(ArgsFont const &a)
{
    emplace<ScArgsFont>({a, m_asset.lookupFont(a.font)});
}
void Draw::fontBox(ArgsFontBox const &a)
{
    emplace<ScArgsFontBox>({a, m_asset.lookupFont(a.font)});
}
void Draw::texture(ArgsTexture const &a)
{
    emplace<ScArgsTexture>({a, m_asset.lookupTexture(a.texture)});
}
void Draw::line(ArgsLine const &a)
{
    emplace<ScArgsLine>({a});
}
void Draw::triangle(ArgsTriangle const &a)
{
    emplace<ScArgsTriangle>({a});
}
void Draw::rectangle(ArgsRectangle const &a)
{
    emplace<ScArgsRectangle>({a});
}
void Draw::inOrderOfZ()
{
    for (auto it = m_draws.begin();
         it != m_draws.end();
         it = std::next(it))
    {
        auto &queue = it->second;

        for (; !queue.empty(); queue.pop())
        {
            queue.front()->Draw();
        }
    }
    m_draws.clear();
}