#include "Wall.hpp"

namespace Pacman {
    Wall::Wall(ArcaTek::Buffer::Vec2<int> position, ArcaTek::Buffer::Vec2<int> size) : Tile(position, size, ArcaTek::Buffer::Colors::RED) {}
}
