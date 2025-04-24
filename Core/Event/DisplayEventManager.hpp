#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/Subject/CloseAppSubject.hpp"
#include <memory>

namespace ArcaTek::Event {
    struct DisplayEventManager {
        std::shared_ptr<Subject::CloseAppSubject> closeApp = std::make_shared<Subject::CloseAppSubject>();
    };
} // namespace ArcaTek::Event
