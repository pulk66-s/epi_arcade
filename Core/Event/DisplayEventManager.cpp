#include "DisplayEventManager.hpp"

namespace ArcaTek::Event
{
    std::shared_ptr<Subject::DrawSquareSubject> DisplayEventManager::drawSquare() const {
        return this->drawSquareSubject;
    }
} // namespace ArcaTek::Event
