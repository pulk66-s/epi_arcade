#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/GameEventManager.hpp"
#include "Core/Buffer/DisplayBuffer.hpp"

class ArcaTek::Game::IGame {
public:
    virtual ~IGame() = default;
    virtual void init(std::shared_ptr<Event::GameEventManager> eventManager, std::shared_ptr<Event::DisplayEventManager> displayEventManager) = 0;
    virtual void update() = 0;
};
