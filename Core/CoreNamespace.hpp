#pragma once

namespace ArcaTek {
    class Core;
    namespace Display {
        class IDisplay;
    } // namespace Display
    namespace Game {
        class IGame;
    } // namespace Game
    namespace Event {
        class ISubject;
        template <typename T>
        class ASubject;
        class IObserver;
        template <typename T>
        class AObserver;
        class GameEventManager;
        class DisplayEventManager;
        namespace Subject {
            class KeyboardSubject;
            class CloseAppSubject;
        } // namespace Subject
        namespace Observer {
            class KeyboardObserver;
            class MouseObserver;
            class GamepadObserver;
        } // namespace Observer
    } // namespace Event
    namespace DLL {
        class IDLL;
        class LDDLL;
    } // namespace DLL
    namespace Buffer {
        class DisplayBuffer;
        class IDrawable;
        class Square;
        template <typename T>
        struct Vec2;
        class Color;
    } // namespace Buffer
} // namespace ArcaTek::Core
