#pragma once

#include "Core/CoreNamespace.hpp"
#include <expected>
#include <string>

namespace ArcaTek::DLL {
    class IDLL {
    public:
        virtual ~IDLL() = default;
        virtual std::expected<void, std::string> load() = 0;
        virtual std::expected<void, std::string> unload() = 0;
        virtual std::string getName() const = 0;
    };
} // namespace ArcaTek::DLL
