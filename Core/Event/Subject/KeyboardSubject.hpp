#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/ASubject.hpp"
#include "Core/Event/Observer/KeyboardObserver.hpp"

namespace ArcaTek::Event::Subject {
    class KeyboardSubject : public ASubject<uint8_t> {
    public:
        KeyboardSubject();
    };
} // namespace ArcaTek::Event::Subject
