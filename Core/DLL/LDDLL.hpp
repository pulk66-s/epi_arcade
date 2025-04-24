#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/DLL/IDLL.hpp"
#include <string>
#include <functional>

namespace ArcaTek::DLL {
    class LDDLL : public IDLL {
    private:
        std::string name;
        void *handle = nullptr;

    public:
        LDDLL(std::string name);
        ~LDDLL();

        std::expected<void, std::string> load();
        std::expected<void, std::string> unload();
        std::string getName() const;
        template <typename Ret, typename... Args>
        std::expected<std::function<Ret(Args...)>, std::string> getSymbol(std::string symbol);
    };
} // namespace ArcaTek::DLL
