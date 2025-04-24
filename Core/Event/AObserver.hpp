#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/IObserver.hpp"
#include <functional>

namespace ArcaTek::Event {
    template <typename T>
    class AObserver : public IObserver {
    private:
        std::function<void(T)> callback = nullptr;

    public:
        AObserver() = default;
        AObserver(std::function<void(T)> callback) : callback(callback) {}
        virtual ~AObserver() = default;

        virtual void update(T data) {
            if (callback) {
                callback(data);
            }
        };
    };
} // namespace ArcaTek::Event
