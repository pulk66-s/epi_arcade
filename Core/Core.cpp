#include "Core.hpp"
#include "Core/DLL/LDDLL.hpp"
#include "Core/Event/Observer/CloseAppObserver.hpp"
#include <iostream>

namespace ArcaTek {
    Core::Core(std::vector<std::string> games, std::vector<std::string> displays) {
        for (std::string path : games)
            this->gameLibs.push_back(DLL::LDDLL(path));
        for (std::string path : displays)
            this->displayLibs.push_back(DLL::LDDLL(path));
        for (DLL::LDDLL &dll : this->gameLibs) {
            std::expected<void, std::string> load = dll.load();

            if (load.has_value()) {
                std::expected<std::function<Game::IGame *()>, std::string> createGame = dll.getSymbol<Game::IGame *>("createGame");

                if (createGame.has_value()) {
                    Game::IGame *game = createGame.value()();
                    this->gameInstances.push_back(std::shared_ptr<Game::IGame>(game));
                } else {
                    std::cerr << "Failed to load game symbol: " << load.error() << std::endl;
                }
            }
        }
        for (DLL::LDDLL &dll : this->displayLibs) {
            std::expected<void, std::string> load = dll.load();

            if (load.has_value()) {
                std::expected<std::function<Display::IDisplay *()>, std::string> createDisplay = dll.getSymbol<Display::IDisplay *>("createDisplay");

                if (createDisplay.has_value()) {
                    Display::IDisplay *display = createDisplay.value()();
                    this->displayInstances.push_back(std::shared_ptr<Display::IDisplay>(display));
                } else {
                    std::cerr << "Failed to load display symbol: " << load.error() << std::endl;
                }
            }
        }
        std::cout << "Loaded " << this->gameInstances.size() << " game instances and " << this->displayInstances.size() << " display instances." << std::endl;
        if (this->gameInstances.empty()) {
            std::cerr << "No game instances loaded." << std::endl;
            return;
        }
        if (this->displayInstances.empty()) {
            std::cerr << "No display instances loaded." << std::endl;
            return;
        }
        this->gameInstances[this->currentGameIndex]->init(this->gameEventManager);
        this->displayInstances[this->currentDisplayIndex]->init(this->displayEventManager);
        this->setupHandlers();
    }

    void Core::setupHandlers() {
        this->displayEventManager.closeApp->attach([this](bool close) {
            if (close) {
                this->running = false;
            }
        });
    }

    Core::~Core() {}

    void Core::run() {
        while (this->running) {
            Buffer::DisplayBuffer buffer = this->gameInstances[this->currentGameIndex]->update();

            this->displayInstances[this->currentDisplayIndex]->render(buffer);
        }
    }
}
