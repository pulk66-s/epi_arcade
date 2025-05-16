#pragma once

#include "PacmanNamespace.hpp"
#include "Tile.hpp"
#include "Core/Buffer/Vec2.hpp"

namespace Pacman {
    class PacGum : public Tile {
        public:
            PacGum(ArcaTek::Buffer::Vec2<int> position, ArcaTek::Buffer::Vec2<int> size);
    };
}
