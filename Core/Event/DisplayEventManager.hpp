#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/Subject/KeyboardSubject.hpp"
#include "Core/Event/Subject/DrawSquareSubject.hpp"
#include <memory>

namespace ArcaTek::Event {
    struct DisplayEventManager {
        std::shared_ptr<Subject::DrawSquareSubject> drawSquare = std::make_shared<Subject::DrawSquareSubject>();
    };
} // namespace ArcaTek::Event
