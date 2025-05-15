#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Buffer/DisplayBuffer.hpp"
#include "Core/Event/DisplayEventManager.hpp"
#include "Core/Event/GameEventManager.hpp"

class ArcaTek::Display::IDisplay {
public:
    virtual ~IDisplay() = default;
    virtual void render() = 0;
    virtual void clear() = 0;
    virtual void init(std::shared_ptr<ArcaTek::Event::GameEventManager> gameEventManager, std::shared_ptr<ArcaTek::Event::DisplayEventManager> displayEventManager) = 0;
};
