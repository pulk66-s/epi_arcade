#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/Subject/DrawSquareSubject.hpp"
#include <memory>

namespace ArcaTek::Event {
    class DisplayEventManager {
    private:
        std::shared_ptr<Subject::DrawSquareSubject> drawSquareSubject = std::make_shared<Subject::DrawSquareSubject>();

    public:
        std::shared_ptr<Subject::DrawSquareSubject> drawSquare() const;
    };
} // namespace ArcaTek::Event
