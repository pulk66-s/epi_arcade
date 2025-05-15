#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/Subject/CloseAppSubject.hpp"
#include <memory>

namespace ArcaTek::Event {
    struct GameEventManager {
        std::shared_ptr<Subject::CloseAppSubject> closeApp = std::make_shared<Subject::CloseAppSubject>();
        std::shared_ptr<Subject::KeyboardSubject> keyPressed = std::make_shared<Subject::KeyboardSubject>();
    };
} // namespace ArcaTek::Event
