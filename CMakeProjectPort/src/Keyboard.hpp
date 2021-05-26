#pragma once

#include <Sc/API/IKeyboard.hpp>

namespace Sc::Internal
{
    struct IKeyboardControl : public IKeyboard
    {
        virtual ~IKeyboardControl(){};
        virtual void update() = 0;
    };

    class Keyboard : public IKeyboardControl
    {
    public:
        Keyboard();
        virtual bool isClicked(EKeyboardKey) const override;
        virtual bool isHeld(EKeyboardKey) const override;
        virtual bool isReleased(EKeyboardKey) const override;
        virtual EKeyboardKey key() const override;
        virtual EKeyboardKey keyLast() const override;

        virtual void update() override;

    private:
        EKeyboardKey m_keyLast;
        EKeyboardKey m_key;
    };

    // Replace our custom "-1 None" key signal
    int defaultNoneKey();
    EKeyboardKey rLibConvertKeyboardKey(int);
    int keyboardKeyConvertSc(EKeyboardKey);
} // namespace Sc::Internal