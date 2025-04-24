#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/AObserver.hpp"
#include <stdint.h>

namespace ArcaTek::Event::Observer {
    class KeyboardObserver : public AObserver<uint8_t> {
    public:
        KeyboardObserver() = default;
        void update(uint8_t code) override;
    };
} // namespace ArcaTek::Event::Observer
