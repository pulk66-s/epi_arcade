#include "Pacman.hpp"
#include "Core/Buffer/Square.hpp"

void Pacman::init(ArcaTek::Event::GameEventManager &eventManager) {
    this->eventManager = std::make_unique<ArcaTek::Event::GameEventManager>(eventManager);
}

ArcaTek::Buffer::DisplayBuffer Pacman::update() {
    ArcaTek::Buffer::DisplayBuffer buffer;

    buffer.add(std::make_shared<ArcaTek::Buffer::Square>(ArcaTek::Buffer::Vec2{20, 20}, ArcaTek::Buffer::Vec2{15, 15}, ArcaTek::Buffer::Color{0, 255, 0}));
    return buffer;
}

extern "C" {
    Pacman *createGame() {
        return new Pacman();
    }
}
