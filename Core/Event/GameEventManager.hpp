#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/Subject/KeyboardSubject.hpp"
#include <memory>

namespace ArcaTek::Event {
    struct GameEventManager {
        std::shared_ptr<Subject::KeyboardSubject> keyboard = std::make_shared<Subject::KeyboardSubject>();
    };
} // namespace ArcaTek::Event
