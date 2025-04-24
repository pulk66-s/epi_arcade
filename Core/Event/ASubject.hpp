#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/ISubject.hpp"
#include "Core/Event/IObserver.hpp"
#include "Core/Event/AObserver.hpp"
#include <vector>

namespace ArcaTek::Event {
    template <typename T>
    class ASubject : public ISubject {
    protected:
        std::vector<std::shared_ptr<IObserver>> observers;

    public:
        ASubject() = default;
        void attach(std::shared_ptr<IObserver> observer);
        void detach(std::shared_ptr<IObserver> observer);
        void notify(T data);
    };        
} // namespace ArcaTek::Event
