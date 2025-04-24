#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/IObserver.hpp"

namespace ArcaTek::Event {
    template <typename T>
    class AObserver : public IObserver {
    public:
        virtual void update(T data);
        virtual ~AObserver() = default;
    };
} // namespace ArcaTek::Event
