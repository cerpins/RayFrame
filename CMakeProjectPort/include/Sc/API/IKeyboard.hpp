#pragma once

namespace Sc
{
    enum class EKeyboardKey : int;
    struct IKeyboard
    {
        virtual ~IKeyboard() {}
        virtual bool isClicked(EKeyboardKey) const = 0;
        virtual bool isHeld(EKeyboardKey) const = 0;
        virtual bool isReleased(EKeyboardKey) const = 0;
        virtual EKeyboardKey key() const = 0;
        virtual EKeyboardKey keyLast() const = 0;
    };

    enum class EKeyboardKey : int
    {
        None = -1,

        Apostrophe = 39,
        Comma = 44,
        Minus = 45,
        Period = 46,
        Slash = 47,
        Zero = 48,
        One = 49,
        Two = 50,
        Three = 51,
        Four = 52,
        Five = 53,
        Six = 54,
        Seven = 55,
        Eight = 56,
        Nine = 57,
        Semicolon = 59,
        Equal = 61,
        a = 65,
        B = 66,
        C = 67,
        D = 68,
        E = 69,
        F = 70,
        G = 71,
        H = 72,
        I = 73,
        J = 74,
        K = 75,
        L = 76,
        M = 77,
        N = 78,
        O = 79,
        P = 80,
        Q = 81,
        R = 82,
        S = 83,
        T = 84,
        U = 85,
        v = 86,
        W = 87,
        X = 88,
        Y = 89,
        Z = 90,

        // Function Keys
        Space = 32,
        Escape = 256,
        Enter = 257,
        Tab = 258,
        Backspace = 259,
        Insert = 260,
        Delete = 261,
        Right = 262,
        Left = 263,
        Down = 264,
        Up = 265,
        PageUp = 266,
        PageDown = 267,
        Home = 268,
        End = 269,
        CapsLock = 280,
        ScrollLock = 281,
        NumLock = 282,
        PrintScreen = 283,
        Pause = 284,
        F1 = 290,
        F2 = 291,
        F3 = 292,
        F4 = 293,
        F5 = 294,
        F6 = 295,
        F7 = 296,
        F8 = 297,
        F9 = 298,
        F10 = 299,
        F11 = 300,
        F12 = 301,
        LeftShift = 340,
        LeftControl = 341,
        LeftAlt = 342,
        LeftSuper = 343,
        RightShift = 344,
        RightControl = 345,
        RightAlt = 346,
        RightSuper = 347,
        KeypadMenu = 348,
        LeftBracket = 91,
        Backslash = 92,
        RightBracket = 93,
        Grave = 96,

        // Keypad Keys
        KeypadZero = 320,
        KeypadOne = 321,
        KeypadTwo = 322,
        KeypadThree = 323,
        KeypadFour = 324,
        KeypadFive = 325,
        KeypadSix = 326,
        KeypadSeven = 327,
        KeypadEight = 328,
        KeypadNine = 329,
        KeypadDecimal = 330,
        KeypadDivide = 331,
        KeypadMultiply = 332,
        KeypadSubtract = 333,
        KeypadAdd = 334,
        KeypadEnter = 335,
        KeypadEqual = 336
    };
} // namespace Sc