#include "Keyboard.hpp"

#include <raylib.h>

using Keyboard = Sc::Internal::Keyboard;

Keyboard::Keyboard()
    : m_keyLast(EKeyboardKey::None),
      m_key(EKeyboardKey::None) {}
bool Keyboard::isClicked(EKeyboardKey key) const
{
    return ::IsKeyPressed(keyboardKeyConvertSc(key));
}

bool Keyboard::isHeld(EKeyboardKey key) const
{
    return ::IsKeyDown(keyboardKeyConvertSc(key));
}
bool Keyboard::isReleased(EKeyboardKey key) const
{
    return ::IsKeyReleased(keyboardKeyConvertSc(key));
}
Sc::EKeyboardKey Keyboard::key() const
{
    return m_key;
}
Sc::EKeyboardKey Keyboard::keyLast() const
{
    return m_keyLast;
}
void Keyboard::update()
{
    m_keyLast = m_key;
    m_key = rLibConvertKeyboardKey(::GetKeyPressed());
}

int Sc::Internal::defaultNoneKey()
{
    return ::KeyboardKey::KEY_RIGHT_SUPER;
}
Sc::EKeyboardKey Sc::Internal::rLibConvertKeyboardKey(int key)
{
    // If EKeyboardKey matches exactly, this should always work.
    return static_cast<Sc::EKeyboardKey>(
        static_cast<int>(key));
}
int Sc::Internal::keyboardKeyConvertSc(Sc::EKeyboardKey key)
{
    if (key == Sc::EKeyboardKey::None)
    {
        return defaultNoneKey();
    }

    // Enums must match except for the none key !!!
    return static_cast<::KeyboardKey>(
        static_cast<int>(key));
}