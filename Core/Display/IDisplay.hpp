#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Buffer/DisplayBuffer.hpp"
#include "Core/Event/DisplayEventManager.hpp"

class ArcaTek::Display::IDisplay {
public:
    virtual ~IDisplay() = default;
    virtual void render(Buffer::DisplayBuffer &buffer) = 0;
    virtual void init(Event::DisplayEventManager &eventManager) = 0;
};
