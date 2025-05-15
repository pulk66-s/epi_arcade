#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/ASubject.hpp"
#include "Core/Event/Observer/KeyboardObserver.hpp"
#include "Core/Event/Key.hpp"

namespace ArcaTek::Event::Subject {
    class KeyboardSubject : public ASubject<ArcaTek::Event::Key> {
    };
} // namespace ArcaTek::Event::Subject
