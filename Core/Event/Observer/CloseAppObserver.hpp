#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/ASubject.hpp"

namespace ArcaTek::Event::Observer
{
    class CloseAppObserver : public AObserver<bool> {
    public:
        CloseAppObserver() = default;
        CloseAppObserver(std::function<void(bool)> callback) : AObserver(callback) {}
    };
} // namespace ArcaTek::Event::Observer
