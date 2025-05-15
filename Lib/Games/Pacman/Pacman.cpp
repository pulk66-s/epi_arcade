#include "Pacman.hpp"
#include "Core/Buffer/Square.hpp"
#include "Core/Event/Key.hpp"

void PacmanGame::init(std::shared_ptr<ArcaTek::Event::GameEventManager> eventManager, std::shared_ptr<ArcaTek::Event::DisplayEventManager> displayEventManager) {
    this->eventManager = eventManager;
    this->displayEventManager = displayEventManager;
    this->handleEvents();
}

void PacmanGame::update() {
    this->player.display(this->displayEventManager);
}

void PacmanGame::handleEvents() {
    this->eventManager->keyPressed->attach([this](ArcaTek::Event::Key key) {
        if (key == ArcaTek::Event::Key::Up) {
            this->player.moveUp();
        } else if (key == ArcaTek::Event::Key::Down) {
            this->player.moveDown();
        } else if (key == ArcaTek::Event::Key::Left) {
            this->player.moveLeft();
        } else if (key == ArcaTek::Event::Key::Right) {
            this->player.moveRight();
        }
    });
}

extern "C" {
    PacmanGame *createGame() {
        return new PacmanGame();
    }
}
