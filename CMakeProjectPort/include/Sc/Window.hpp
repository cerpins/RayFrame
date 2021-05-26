#pragma once

#include <string>

#include <Core/Aliases.hpp>
#include <Core/Trivial.hpp>
#include <Core/ASingular.hpp>

#include <Sc/IWindowControl.hpp>
#include <Sc/WindowAPI.hpp>

namespace Core
{
    struct Size;
}

namespace Sc
{
    namespace Internal
    {
        struct IAssetControl;
        struct IMouseControl;
        struct IDrawControl;
        struct IKeyboardControl;
    } // namespace Internal

    struct WindowSettings
    {
        // Incorrect ATM; should only be runtime unchangable settings.
        Core::Size const size;
        std::string const title;
    };
    /*  Sets up systems, passes a restricted version of them
        to the user.
    */
    class Window final
        : public IWindowControl,
          public Core::ASingular<Window>
    {
    public:
        Window(WindowSettings const &, UP<IWindowScreen>);
        ~Window(); // Clean up system before closing

        // From IWindowControl
        virtual bool tickFrame() override;
        virtual void swapScreen(UP<IWindowScreen> nextScreen) override;

    private:
        /* Define internal calls for extra settings
        */
        Core::Size m_size;
        std::string m_title;

        UP<Internal::IAssetControl> m_upAsset;
        UP<Internal::IDrawControl> m_upDraw;
        UP<Internal::IMouseControl> m_upMouse;
        UP<Internal::IKeyboardControl> m_upKeyboard;

        UP<IWindowScreen> m_screenCurrent;
        UP<IWindowScreen> m_screenNext;
    };
} // namespace Sc