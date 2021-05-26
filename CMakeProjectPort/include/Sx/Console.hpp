#pragma once

#include <string>
#include <map>

#include <Core/Trivial.hpp>
#include <Sc/API/IAsset.hpp>
#include <Sc/API/IDraw.hpp>

namespace Sx
{
    // User WindowAPI
    struct IConsole
    {
        virtual ~IConsole(){};
        virtual void log(
            std::string const &key,
            std::string const &message,
            float const life) = 0;
    };

    class Console : public IConsole
    {
    public:
        Console(
            Sc::Font const &font,
            Core::Color const &background);
        void update(Sc::IDraw &draw);
        void show();
        void hide();
        virtual void log(
            std::string const &key,
            std::string const &message,
            float const life) override;

    private:
        Sc::Font const m_font;
        Core::Color const m_background;

        bool m_isVisible{false};
        std::map<
            std::string,
            std::pair<std::string, float>>
            m_logs;
    };
} // namespace Sx