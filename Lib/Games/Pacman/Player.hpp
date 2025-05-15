#pragma once

#include "PacmanNamespace.hpp"
#include "Core/Buffer/Square.hpp"
#include "Core/Event/DisplayEventManager.hpp"

namespace Pacman {
    class Player {
        private:
            ArcaTek::Buffer::Square square = ArcaTek::Buffer::Square(ArcaTek::Buffer::Vec2{20, 20}, ArcaTek::Buffer::Vec2{15, 15}, ArcaTek::Buffer::Color{0, 255, 0, 255});

        public:
            void display(std::shared_ptr<ArcaTek::Event::DisplayEventManager> displayEventManager) {
                displayEventManager->drawSquare->notify(this->square);
            }

            void moveUp() {
                this->square.pos.y -= 1;
            }

            void moveDown() {
                this->square.pos.y += 1;
            }

            void moveLeft() {
                this->square.pos.x -= 1;
            }

            void moveRight() {
                this->square.pos.x += 1;
            }
    };
}
