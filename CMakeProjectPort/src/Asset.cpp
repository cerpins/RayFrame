#include "Asset.hpp"

#include <algorithm>
#include <iostream>

#include <raylib.h>

#include "Convert.hpp"

using InfoTexture = Sc::Internal::InfoTexture;
using InfoFont = Sc::Internal::InfoFont;
using Asset = Sc::Internal::Asset;

/* Helpers
*/

Sc::Texture makeTexture(size_t index, ::Texture const &rlibTexture)
{
    return {
        index,
        static_cast<float>(rlibTexture.width),
        static_cast<float>(rlibTexture.height)};
}

// Util
bool InfoTexture::operator==(InfoTexture const &compare) const
{
    return (
        pathAndName == compare.pathAndName &&
        mod == compare.mod);
}
bool InfoFont::operator==(InfoFont const &compare) const
{
    return (
        pathAndName == compare.pathAndName &&
        size == compare.size);
}

//
Asset::~Asset()
{
    for (auto &pair : m_textures)
    {
        UnloadTexture(pair.second);
    }

    for (auto &pair : m_fonts)
    {
        UnloadFont(pair.second);
    }
}

Sc::Texture Asset::loadTexture(
    std::string const &pathAndName,
    ETextureMod const mod)
{
    InfoTexture info = {pathAndName, mod};

    auto find = std::find_if(
        m_textures.begin(),
        m_textures.end(),
        [&](auto const &pair) {
            return pair.first == info;
        });

    bool alreadyLoaded = find != m_textures.end();
    if (alreadyLoaded)
    {
        return makeTexture(
            static_cast<size_t>(std::distance(m_textures.begin(), find)),
            find->second);
    }

    // Not previously loaded
    std::cout << GetWorkingDirectory() << std::endl;
    auto const path = m_assetRoot + pathAndName;
    auto const texture = ::LoadTexture(path.c_str());

    m_textures.emplace_back(std::make_pair(info, texture));
    return makeTexture(m_textures.size() - 1, texture);
}

Sc::Font Asset::loadFont(
    std::string const &pathAndName,
    float const size)
{
    InfoFont info = {pathAndName, size};
    auto find = std::find_if(
        m_fonts.begin(),
        m_fonts.end(),
        [&](auto const &pair) {
            return pair.first == info;
        });

    bool alreadyLoaded = find != m_fonts.end();
    if (alreadyLoaded)
    {
        return Sc::Font{
            static_cast<size_t>(std::distance(m_fonts.begin(), find)),
            size};
    }

    // Not previously loaded
    auto const path = m_assetRoot + pathAndName;
    auto const font = ::LoadFontEx(
        path.c_str(),
        static_cast<int>(size),
        0, 0);

    m_fonts.emplace_back(info, font);
    return Sc::Font{m_fonts.size() - 1, size};
}

::Texture Asset::lookupTexture(Sc::Texture const &texture)
{
    return m_textures.size() > texture.id
               ? m_textures[texture.id].second
               : ::Texture();
}

::Font Asset::lookupFont(Sc::Font const &font)
{
    return m_fonts.size() > font.id
               ? m_fonts[font.id].second
               : ::Font();
}