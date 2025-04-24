#pragma once

#include "Core/CoreNamespace.hpp"

namespace ArcaTek::Event {
    class IObserver {
    public:
        virtual ~IObserver() = default;
    };
} // namespace ArcaTek::Event
