#include "Map.hpp"
#include "Wall.hpp"
#include "PacGum.hpp"

namespace Pacman {
    Map::Map(std::string file) {
        std::ifstream mapFile(file);
        std::string line;
        int x = 0;
        int y = 0;

        if (!mapFile.is_open()) {
            std::cout << "Error: Map file not found" << std::endl;
            return;
        }
        while (std::getline(mapFile, line)) {
            for (const char &c : line) {
                switch (c) {
                    case '#':
                        this->tiles.push_back(Wall(ArcaTek::Buffer::Vec2<int>(x * 10, y * 10), ArcaTek::Buffer::Vec2<int>(10, 10)));
                        break;
                    case '.':
                        this->tiles.push_back(PacGum(ArcaTek::Buffer::Vec2<int>(x * 10, y * 10), ArcaTek::Buffer::Vec2<int>(10, 10)));
                        break;
                }
                x++;
            }
            y++;
            x = 0;
        }
        mapFile.close();
    }

    Map::Map(std::vector<Tile> tiles) {
        this->tiles = tiles;
    }

    void Map::display(std::shared_ptr<ArcaTek::Event::DisplayEventManager> displayEventManager) {
        for (Tile tile : this->tiles) {
            tile.display(displayEventManager);
        }
    }
}
