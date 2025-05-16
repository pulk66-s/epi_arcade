#pragma once

#include "PacmanNamespace.hpp"
#include "Core/Buffer/Vec2.hpp"
#include "Core/Buffer/Color.hpp"
#include "Core/Event/DisplayEventManager.hpp"
#include <memory>

namespace Pacman {
    class Tile {
        private:
            ArcaTek::Buffer::Vec2<int> position;
            ArcaTek::Buffer::Vec2<int> size;
            ArcaTek::Buffer::Color color;

        public:
            Tile(ArcaTek::Buffer::Vec2<int> position, ArcaTek::Buffer::Vec2<int> size, ArcaTek::Buffer::Color color);

            void display(std::shared_ptr<ArcaTek::Event::DisplayEventManager> displayEventManager);
    };
}
