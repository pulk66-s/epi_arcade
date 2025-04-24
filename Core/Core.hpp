#pragma once

#include "CoreNamespace.hpp"
#include "Event/GameEventManager.hpp"
#include "Event/DisplayEventManager.hpp"
#include "Display/IDisplay.hpp"
#include "Game/IGame.hpp"
#include "DLL/LDDLL.hpp"
#include <vector>
#include <string>
#include <memory>

class ArcaTek::Core {
    private:
        std::vector<DLL::LDDLL> gameLibs = {};
        std::vector<DLL::LDDLL> displayLibs = {};
        std::vector<std::shared_ptr<Game::IGame>> gameInstances = {};
        std::vector<std::shared_ptr<Display::IDisplay>> displayInstances = {};
        std::size_t currentGameIndex = 0;
        std::size_t currentDisplayIndex = 0;
        Event::GameEventManager gameEventManager;
        Event::DisplayEventManager displayEventManager;
        bool running = true;

        void setupHandlers();

    public:
        Core(std::vector<std::string> gameDlls, std::vector<std::string> displayDlls);
        ~Core();

        void run();
};
