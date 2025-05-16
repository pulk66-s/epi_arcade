#include "PacGum.hpp"

namespace Pacman {
    PacGum::PacGum(ArcaTek::Buffer::Vec2<int> position, ArcaTek::Buffer::Vec2<int> size): Tile(position, size, ArcaTek::Buffer::Colors::YELLOW) {
    }
}
