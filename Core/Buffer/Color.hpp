#pragma once

namespace ArcaTek::Buffer
{
    struct Color {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    };

    namespace Colors {
        const Color RED = {255, 0, 0, 255};
        const Color GREEN = {0, 255, 0, 255};
        const Color BLUE = {0, 0, 255, 255};
        const Color YELLOW = {255, 255, 0, 255};
        const Color CYAN = {0, 255, 255, 255};
        const Color MAGENTA = {255, 0, 255, 255};
    }
} // namespace ArcaTek::Buffer
