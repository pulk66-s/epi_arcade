#include "GameEventManager.hpp"

namespace ArcaTek::Event
{
    std::shared_ptr<Subject::KeyboardSubject> GameEventManager::keyboard() const {
        return this->keyboardSubject;
    }
} // namespace ArcaTek::Event
