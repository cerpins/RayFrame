#include <Sc/Window.hpp>

#include <raylib.h>

#include <Core/Trivial.hpp>
#include <Sc/WindowAPI.hpp>
#include <Sc/IWindowScreen.hpp>

#include "Asset.hpp"
#include "Draw.hpp"
#include "Mouse.hpp"
#include "Keyboard.hpp"

using Window = Sc::Window;

Window::Window(
    WindowSettings const &settings,
    UP<IWindowScreen> screen)
    : m_size(settings.size),
      m_title(settings.title),
      m_upAsset(std::make_unique<Internal::Asset>()),
      m_upDraw(std::make_unique<Internal::Draw>(*m_upAsset)),
      m_upMouse(std::make_unique<Internal::Mouse>()),
      m_upKeyboard(std::make_unique<Internal::Keyboard>()),

      m_screenCurrent(nullptr),
      m_screenNext(std::move(screen))
{
    bool locksCursor = true;
    unsigned int flags =
        FLAG_WINDOW_RESIZABLE |
        // FLAG_MSAA_4X_HINT |
        FLAG_VSYNC_HINT;

    SetConfigFlags(flags);
    InitWindow(
        static_cast<int>(m_size.width),
        static_cast<int>(m_size.height), m_title.c_str());
    SetTargetFPS(60);
    ClearBackground(RAYWHITE);

    locksCursor ? DisableCursor() : HideCursor();

    m_upMouse->UpdateScreenSize(m_size);

    WindowAPI api = {
        *m_upAsset,
        *m_upDraw,
        *m_upMouse,
        *m_upKeyboard};

    /* The fun begins
    */
    while (m_screenNext != nullptr && !::WindowShouldClose())
    {
        m_screenCurrent.reset();
        m_screenCurrent.swap(m_screenNext);
        m_screenCurrent->start(*this, api);
    }
}
Window::~Window()
{
    m_upAsset.reset();
    m_upDraw.reset();
    m_upMouse.reset();
    m_upKeyboard.reset();

    m_screenCurrent.reset();
    m_screenNext.reset();
    CloseWindow();
}
bool Window::tickFrame()
{
    ::BeginDrawing();
    ::ClearBackground(::RAYWHITE);
    m_upMouse->update();
    m_upKeyboard->update();
    m_upDraw->inOrderOfZ();
    ::EndDrawing();

    bool isNextScreenReady = m_screenNext != nullptr;
    if (isNextScreenReady || ::WindowShouldClose())
    {
        return false;
    }
    return true;
}
void Window::swapScreen(UP<IWindowScreen> nextScreen)
{
    m_screenNext = std::move(nextScreen);
}