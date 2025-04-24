#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/Subject/KeyboardSubject.hpp"
#include <memory>

namespace ArcaTek::Event {
    class GameEventManager {
    private:
        std::shared_ptr<Subject::KeyboardSubject> keyboardSubject = std::make_shared<Subject::KeyboardSubject>();

    public:
        std::shared_ptr<Subject::KeyboardSubject> keyboard() const;
    };
} // namespace ArcaTek::Event
