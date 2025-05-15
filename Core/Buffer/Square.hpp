#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Buffer/IDrawable.hpp"
#include "Core/Buffer/Vec2.hpp"
#include "Core/Buffer/Color.hpp"
#include <iostream>

namespace ArcaTek::Buffer {
    class Square : public IDrawable {
    public:
        Vec2<int> pos;
        Vec2<int> size;
        Color color;

        Square(const Vec2<int>& pos, const Vec2<int>& size, const Color& color) 
            : pos(pos), size(size), color(color) {}

        ~Square() override = default;

        DrawableType getType() override {
            return DrawableType::Square;
        }
    };
} // namespace ArcaTek::Buffer
