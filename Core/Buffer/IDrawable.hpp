#pragma once

#include "Core/CoreNamespace.hpp"

namespace ArcaTek::Buffer {
    enum class DrawableType {
        Square,
    };

    class IDrawable {
    public:
        virtual ~IDrawable() = default;
        virtual DrawableType getType() = 0;
    };
} // namespace ArcaTek::Buffer
