#include <Sx/Gui.hpp>

#include <string>
#include <cmath>
#include <Core/Utility.hpp>
#include <Core/Invariant.hpp>
#include <Sx/Draw.hpp>

/*
    0) Factory which is initialized using settings
    1) General highly paramterized functions for drawing (Box, Text, Etc)
    2) States that draw them according to some principle

    Layers:
    Pre-defined layer which always follows settings
    Compositional layer which has user interfaces
*/

// Functions for drawing stateless elements
void drawGuiBox(
    Sc::IDraw &api,
    Sx::GuiConfig const &config,
    Core::Rectangle const &shape,
    float const colorRate = 0.f)
{
    Core::Color bg = config.backgroundColor;

    if (colorRate > 0.f)
    {
        // 1.f so we go from light to dark
        bg = Core::colorMultiplyRGB(bg, 1.f + colorRate);
    }

    Sx::drawRectangleBasic(
        api, config.z,
        shape, bg);
}

void drawGuiLabel(
    Sc::IDraw &api,
    Sx::GuiConfig const &config,
    Core::Rectangle const &rect,
    std::string const &text,
    float const colorRate = 0.f)
{
    drawGuiBox(api, config, rect, colorRate);
    Sx::drawFontBoxBasic(
        api, config.z, config.fontMedium,
        text,
        {rect.point.x + config.padding, rect.point.y + config.padding, rect.size},
        config.fontColor);
}

// Factory
using FactoryForGui = Sx::FactoryForGui;
FactoryForGui::FactoryForGui(GuiConfig const &cfg)
    : m_config(cfg) {}
Sx::GuiLabel FactoryForGui::label(
    Core::Rectangle const &shape, std::string const &text) const
{
    return GuiLabel(m_config, shape, text);
}
Sx::GuiButton FactoryForGui::button(
    Core::Rectangle const &shape, std::string const &text) const
{
    return GuiButton(m_config, shape, text);
}
Sx::GuiImgToggle FactoryForGui::imgToggle(
    Core::Rectangle const &shape, Sc::Texture const &tex,
    float const scale) const
{
    return GuiImgToggle(m_config, shape, tex, scale);
}

// Gui
using GuiLabel = Sx::GuiLabel;
GuiLabel::GuiLabel(
    GuiConfig const &cfg,
    Core::Rectangle const &rect, std::string const &text)
    : m_config(cfg), m_shape(rect), m_text(text) {}
void GuiLabel::draw(Sc::IDraw &api) const
{
    drawGuiLabel(api, m_config, m_shape, m_text);
}

using GuiButton = Sx::GuiButton;
GuiButton::GuiButton(
    GuiConfig const &cfg,
    Core::Rectangle const &shape, std::string const &text)
    : m_config(cfg), m_shape(shape), m_text(text) {}
void GuiButton::draw(Sc::IDraw &api) const
{
    m_activeTick = std::max(m_activeTick - m_config.bgColorMultiRate, 0.f);
    m_highlightTick = std::max(m_highlightTick - m_config.bgColorMultiRate, 0.f);

    drawGuiLabel(
        api, m_config,
        m_shape, m_text,
        m_activeTick > m_highlightTick ? m_activeTick : m_highlightTick);
}

void GuiButton::action(EButtonAction const action)
{
    m_activeTick =
        EButtonAction::Click == action
            ? m_config.bgColorActivateMulti
            : m_config.bgColorHighlightMulti;
}
// Replace this and highlight with just Active and Enum
void GuiButton::click()
{
    m_activeTick = m_config.bgColorActivateMulti;
}
void GuiButton::hover()
{
    m_highlightTick = m_config.bgColorHighlightMulti;
}
bool GuiButton::isCollision(Core::Point const &cursor) const
{
    return Core::isPointIn(cursor, m_shape);
}

using GuiImgToggle = Sx::GuiImgToggle;
GuiImgToggle::GuiImgToggle(
    GuiConfig const &cfg, Core::Rectangle const &shape,
    Sc::Texture const &tex, float const scale)
    : m_config(cfg),
      m_shape(shape), m_texture(tex),
      m_scale(scale) {}
void GuiImgToggle::draw(Sc::IDraw &api) const
{
    drawGuiBox(api, m_config, m_shape);

    float const yFitAndScale =
        (1 / (m_texture.size.height / m_shape.size.height)) * m_scale;
    Core::Size const fitSize = {
        m_texture.size.width * yFitAndScale,
        m_texture.size.height * yFitAndScale};

    Sx::drawTexture(
        api, m_config.z, m_texture,
        {0, 0, m_texture.size.width, m_texture.size.height},
        {m_shape.point.x + m_shape.size.width / 2.f,
         m_shape.point.y + m_shape.size.height / 2.f, fitSize},
        {fitSize.width / 2.f, fitSize.height / 2.f},
        0,
        m_isVisible ? Core::g_colorWhite : Core::g_colorBlack);
}
void GuiImgToggle::show()
{
    m_isVisible = true;
}
void GuiImgToggle::hide()
{
    m_isVisible = false;
}
bool GuiImgToggle::isVisible() const
{
    return m_isVisible;
}
bool GuiImgToggle::isCollide(Core::Point const &cursor) const
{
    return Core::isPointIn(cursor, m_shape);
}

// using GuiLabel = Sx::GuiLabel;
// using GuiButton = Sx::GuiButton;

// GUI INTERFACES
