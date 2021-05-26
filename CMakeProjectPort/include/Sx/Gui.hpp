#pragma once

#include <string>
#include <Core/Trivial.hpp>
#include <Core/Aliases.hpp>
#include <Sc/WindowAPI.hpp>
#include <Sx/IClickable.hpp>

/*  Assumptions:
        Expose all gettable/settable members internally.

        Define a few basic Gui elements and then compose them
        instead of inheriting.

        "Export" internal gui elements as interfaces.
    */

/*  How to define GUI elements:
    Create Imp (Ptr to implementation) for element.
    Adapt internal El class to Imp, instantiate using setting 
*/

namespace Sx
{
    struct GuiConfig
    {
        int z;
        Core::Color backgroundColor{0, 0, 0, 255};
        float bgColorActivateMulti{1.8f};
        float bgColorHighlightMulti{1.1f};
        float bgColorMultiRate{0.05f};
        Sc::Font fontSmall{};
        Sc::Font fontMedium{};
        Sc::Font fontLarge{};
        Core::Color fontColor{255, 255, 255, 255};
        float padding{5};
    };

    // Various Gui
    class GuiLabel
    {
    public:
        GuiLabel() = default;
        GuiLabel(
            GuiConfig const &,
            Core::Rectangle const &, std::string const &);
        void draw(Sc::IDraw &api) const;

    private:
        GuiConfig m_config;
        Core::Rectangle m_shape;
        std::string m_text;
    };

    enum class EButtonAction
    {
        Click,
        Highlight
    };

    class GuiButton
    {
    public:
        GuiButton() = default;
        GuiButton(GuiConfig const &, Core::Rectangle const &,
                  std::string const &);
        void draw(Sc::IDraw &api) const;
        void action(EButtonAction const);
        // Deprecated
        void click();
        // Deprecated
        void hover();
        bool isCollision(Core::Point const &) const;

    private:
        GuiConfig m_config;
        Core::Rectangle m_shape;
        std::string m_text;

        // Move into update fn
        mutable float m_activeTick{0};
        mutable float m_highlightTick{0};
    };

    class GuiImgToggle
    {
    public:
        GuiImgToggle() = default;
        GuiImgToggle(
            GuiConfig const &, Core::Rectangle const &,
            Sc::Texture const &, float const scale);
        void draw(Sc::IDraw &api) const;
        void show();
        void hide();
        bool isVisible() const;
        bool isCollide(Core::Point const &) const;

    private:
        GuiConfig m_config;
        Core::Rectangle m_shape;
        Sc::Texture m_texture;
        float m_scale;
        bool m_isVisible{true};
    };

    // Factory for convenience
    // Pass setting to members intrinsicly
    class FactoryForGui
    {
    public:
        FactoryForGui(GuiConfig const &);

        GuiLabel label(Core::Rectangle const &, std::string const &) const;
        GuiButton button(Core::Rectangle const &, std::string const &) const;
        GuiImgToggle imgToggle(
            Core::Rectangle const &, Sc::Texture const &,
            float const scale) const;

    private:
        GuiConfig m_config;
    };

} // namespace Sx