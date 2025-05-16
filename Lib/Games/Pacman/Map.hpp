#pragma once

#include "PacmanNamespace.hpp"
#include "Tile.hpp"
#include "Wall.hpp"
#include <vector>
#include <string>
#include <fstream>

namespace Pacman {
    class Map {
        private:
            std::vector<Tile> tiles = {};

        public:
            Map(std::string file);
            Map(std::vector<Tile> tiles);

            void display(std::shared_ptr<ArcaTek::Event::DisplayEventManager> displayEventManager);
    };
}
