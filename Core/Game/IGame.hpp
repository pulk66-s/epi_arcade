#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/GameEventManager.hpp"
#include "Core/Buffer/DisplayBuffer.hpp"

class ArcaTek::Game::IGame {
public:
    virtual ~IGame() = default;
    virtual void init(Event::GameEventManager &eventManager) = 0;
    virtual Buffer::DisplayBuffer update() = 0;
};
