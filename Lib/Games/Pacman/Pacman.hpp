#pragma once

#include "Core/Game/IGame.hpp"
#include "Core/Event/DisplayEventManager.hpp"
#include "Core/Event/GameEventManager.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include <memory>

class PacmanGame : public ArcaTek::Game::IGame {
    private:
        std::shared_ptr<ArcaTek::Event::GameEventManager> eventManager = nullptr;
        std::shared_ptr<ArcaTek::Event::DisplayEventManager> displayEventManager = nullptr;
        Pacman::Player player;
        Pacman::Map map;

    public:
        PacmanGame();
        void init(std::shared_ptr<ArcaTek::Event::GameEventManager> eventManager, std::shared_ptr<ArcaTek::Event::DisplayEventManager> displayEventManager);
        void update();
    
    private:
        void handleEvents();
};
