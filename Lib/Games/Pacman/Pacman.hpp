#pragma once

#include "Core/Game/IGame.hpp"
#include "Core/Buffer/DisplayBuffer.hpp"
#include "Core/Event/GameEventManager.hpp"
#include <memory>

class Pacman : public ArcaTek::Game::IGame {
    private:
        std::unique_ptr<ArcaTek::Event::GameEventManager> eventManager;

    public:
        void init(ArcaTek::Event::GameEventManager &eventManager);
        ArcaTek::Buffer::DisplayBuffer update();
};
