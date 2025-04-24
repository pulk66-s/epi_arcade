#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/IObserver.hpp"
#include <memory>

namespace ArcaTek::Event {
    class ISubject {
    public:
        virtual void attach(std::shared_ptr<IObserver> observer) = 0;
        virtual void detach(std::shared_ptr<IObserver> observer) = 0;
    };
} // namespace ArcaTek::Event
