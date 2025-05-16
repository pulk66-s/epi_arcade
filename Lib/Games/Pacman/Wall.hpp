#pragma once

#include "PacmanNamespace.hpp"
#include "Tile.hpp"
#include "Core/Buffer/Color.hpp"
#include "Core/Buffer/Vec2.hpp"

namespace Pacman {
    class Wall : public Tile {
        public:
            Wall(ArcaTek::Buffer::Vec2<int> position, ArcaTek::Buffer::Vec2<int> size);
    };
}
