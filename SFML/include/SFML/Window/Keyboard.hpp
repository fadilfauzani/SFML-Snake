////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_KEYBOARD_HPP
#define SFML_KEYBOARD_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Export.hpp>


namespace sf
{
////////////////////////////////////////////////////////////
/// \brief Give access to the real-time state of the keyboard
///
////////////////////////////////////////////////////////////
class SFML_WINDOW_API Keyboard
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Key codes
    ///
    ////////////////////////////////////////////////////////////
    enum Key
    {
        Unknown = -1, ///< Unhandled key
        A = 0,        ///< The A key 
        B,            ///< The B key 1
        C,            ///< The C key 2
        D,            ///< The D key 3 
        E,            ///< The E key 4
        F,            ///< The F key 5 
        G,            ///< The G key 6
        H,            ///< The H key 7
        I,            ///< The I key 8
        J,            ///< The J key 9 
        K,            ///< The K key 10
        L,            ///< The L key 11
        M,            ///< The M key 12
        N,            ///< The N key 13
        O,            ///< The O key 14
        P,            ///< The P key 15
        Q,            ///< The Q key 16
        R,            ///< The R key 17
        S,            ///< The S key 18
        T,            ///< The T key 19
        U,            ///< The U key 20
        V,            ///< The V key 21
        W,            ///< The W key 22
        X,            ///< The X key 23
        Y,            ///< The Y key 24
        Z,            ///< The Z key 25
        Num0,         ///< The 0 key 26
        Num1,         ///< The 1 key 27
        Num2,         ///< The 2 key 28
        Num3,         ///< The 3 key 29
        Num4,         ///< The 4 key 30
        Num5,         ///< The 5 key 31
        Num6,         ///< The 6 key 32
        Num7,         ///< The 7 key 33
        Num8,         ///< The 8 key 34
        Num9,         ///< The 9 key 35
        Escape,       ///< The Escape key 36
        LControl,     ///< The left Control key 37
        LShift,       ///< The left Shift key 38
        LAlt,         ///< The left Alt key 39
        LSystem,      ///< The left OS specific key: window (Windows and Linux), apple (MacOS X), ... 40
        RControl,     ///< The right Control key 41
        RShift,       ///< The right Shift key 42
        RAlt,         ///< The right Alt key 43
        RSystem,      ///< The right OS specific key: window (Windows and Linux), apple (MacOS X), ... 44
        Menu,         ///< The Menu key 45
        LBracket,     ///< The [ key 46
        RBracket,     ///< The ] key 47
        Semicolon,    ///< The ; key 48
        Comma,        ///< The , key 49
        Period,       ///< The . key 50
        Quote,        ///< The ' key 51
        Slash,        ///< The / key 52
        Backslash,    ///< The \ key 53
        Tilde,        ///< The ~ key 54
        Equal,        ///< The = key 55
        Hyphen,       ///< The - key (hyphen) 56
        Space,        ///< The Space key 57
        Enter,        ///< The Enter/Return keys 58
        Backspace,    ///< The Backspace key 59
        Tab,          ///< The Tabulation key 60
        PageUp,       ///< The Page up key 61
        PageDown,     ///< The Page down key 62
        End,          ///< The End key 63
        Home,         ///< The Home key 64
        Insert,       ///< The Insert key 65
        Delete,       ///< The Delete key 66
        Add,          ///< The + key 67
        Subtract,     ///< The - key (minus, usually from numpad) 68
        Multiply,     ///< The * key 69
        Divide,       ///< The / key 70
        Left,         ///< Left arrow 71 
        Right,        ///< Right arrow 72
        Up,           ///< Up arrow 73
        Down,         ///< Down arrow 74
        Numpad0,      ///< The numpad 0 key 75
        Numpad1,      ///< The numpad 1 key 76
        Numpad2,      ///< The numpad 2 key 77
        Numpad3,      ///< The numpad 3 key 78
        Numpad4,      ///< The numpad 4 key 79
        Numpad5,      ///< The numpad 5 key 80
        Numpad6,      ///< The numpad 6 key 82
        Numpad7,      ///< The numpad 7 key
        Numpad8,      ///< The numpad 8 key
        Numpad9,      ///< The numpad 9 key
        F1,           ///< The F1 key
        F2,           ///< The F2 key
        F3,           ///< The F3 key
        F4,           ///< The F4 key
        F5,           ///< The F5 key
        F6,           ///< The F6 key
        F7,           ///< The F7 key
        F8,           ///< The F8 key
        F9,           ///< The F9 key
        F10,          ///< The F10 key
        F11,          ///< The F11 key
        F12,          ///< The F12 key
        F13,          ///< The F13 key
        F14,          ///< The F14 key
        F15,          ///< The F15 key
        Pause,        ///< The Pause key

        KeyCount,     ///< Keep last -- the total number of keyboard keys

        // Deprecated values:

        Dash      = Hyphen,       ///< \deprecated Use Hyphen instead
        BackSpace = Backspace,    ///< \deprecated Use Backspace instead
        BackSlash = Backslash,    ///< \deprecated Use Backslash instead
        SemiColon = Semicolon,    ///< \deprecated Use Semicolon instead
        Return    = Enter         ///< \deprecated Use Enter instead
    };

    ////////////////////////////////////////////////////////////
    /// \brief Check if a key is pressed
    ///
    /// \param key Key to check
    ///
    /// \return True if the key is pressed, false otherwise
    ///
    ////////////////////////////////////////////////////////////
    static bool isKeyPressed(Key key);

    ////////////////////////////////////////////////////////////
    /// \brief Show or hide the virtual keyboard
    ///
    /// Warning: the virtual keyboard is not supported on all
    /// systems. It will typically be implemented on mobile OSes
    /// (Android, iOS) but not on desktop OSes (Windows, Linux, ...).
    ///
    /// If the virtual keyboard is not available, this function does
    /// nothing.
    ///
    /// \param visible True to show, false to hide
    ///
    ////////////////////////////////////////////////////////////
    static void setVirtualKeyboardVisible(bool visible);
};

} // namespace sf


#endif // SFML_KEYBOARD_HPP


////////////////////////////////////////////////////////////
/// \class sf::Keyboard
/// \ingroup window
///
/// sf::Keyboard provides an interface to the state of the
/// keyboard. It only contains static functions (a single
/// keyboard is assumed), so it's not meant to be instantiated.
///
/// This class allows users to query the keyboard state at any
/// time and directly, without having to deal with a window and
/// its events. Compared to the KeyPressed and KeyReleased events,
/// sf::Keyboard can retrieve the state of a key at any time
/// (you don't need to store and update a boolean on your side
/// in order to know if a key is pressed or released), and you
/// always get the real state of the keyboard, even if keys are
/// pressed or released when your window is out of focus and no
/// event is triggered.
///
/// Usage example:
/// \code
/// if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
/// {
///     // move left...
/// }
/// else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
/// {
///     // move right...
/// }
/// else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
/// {
///     // quit...
/// }
/// \endcode
///
/// \see sf::Joystick, sf::Mouse, sf::Touch
///
////////////////////////////////////////////////////////////
