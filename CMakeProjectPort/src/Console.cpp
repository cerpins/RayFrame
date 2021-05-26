#include <Sx/Console.hpp>

#include <Core/Utility.hpp>
#include <Sx/Draw.hpp>

using Console = Sx::Console;

Console::Console(
    Sc::Font const &font,
    Core::Color const &background)
    : m_font(font),
      m_background(background)
{
}
void Console::update(Sc::IDraw &draw)
{
    float line = 0;
    float lineHeight = 30;
    float margin = 15;
    for (auto it = m_logs.begin();
         it != m_logs.end();)
    {
        auto &life = it->second.second;
        if (--life < 0)
        {
            it = m_logs.erase(it);
            continue;
        }

        if (m_isVisible)
        {
            // Fade when about to disappear
            float fade = life < 70.f ? (life / 70.f) + .7f : 1.f;

            auto &message = it->second.first;
            auto &key = it->first;
            float lineY = margin + lineHeight * line++;
            Sx::drawFontBasic(
                draw, 10001, m_font,
                key + ": " + message,
                {0.f, lineY},
                Core::colorNormal(1.f, 1.f, 1.f, fade));
        }

        it++;
    }

    if (!m_isVisible)
    {
        return;
    }

    float height = margin * 2 + lineHeight * line;
    Sx::drawRectangleBasic(
        draw, 10000,
        {0, 0, 1000, height},
        m_background);
}
void Console::show()
{
    m_isVisible = true;
}
void Console::hide()
{
    m_isVisible = false;
}
void Console::log(
    std::string const &key,
    std::string const &message,
    float const life)
{
    m_logs[key] = std::make_pair(message, life);
}
