#include "Tile.hpp"

namespace Pacman {
    Tile::Tile(ArcaTek::Buffer::Vec2<int> position, ArcaTek::Buffer::Vec2<int> size, ArcaTek::Buffer::Color color) {
        this->position = position;
        this->size = size;
        this->color = color;
    }

    void Tile::display(std::shared_ptr<ArcaTek::Event::DisplayEventManager> displayEventManager) {
        displayEventManager->drawSquare->notify(ArcaTek::Buffer::Square(this->position, this->size, this->color));
    }
}
