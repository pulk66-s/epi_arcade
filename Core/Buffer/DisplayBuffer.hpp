#pragma once

#include <memory>
#include <vector>
#include "Core/CoreNamespace.hpp"
#include "IDrawable.hpp"

namespace ArcaTek::Buffer {
    class DisplayBuffer {
        private:
            std::vector<std::shared_ptr<IDrawable>> drawables = {};

        public:
            void add(std::shared_ptr<IDrawable> drawable) { this->drawables.push_back(drawable); }

            std::vector<std::shared_ptr<IDrawable>> getDrawables() const { return this->drawables; }
    };
}  // namespace ArcaTek::Buffer
