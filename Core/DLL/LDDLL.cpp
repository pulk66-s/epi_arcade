#include "Core/DLL/LDDLL.hpp"
#include <dlfcn.h>
#include <memory>

namespace ArcaTek::DLL {
    LDDLL::LDDLL(std::string name) {
        this->name = name;
    }

    LDDLL::~LDDLL() {
        this->unload();
    }

    std::expected<void, std::string> LDDLL::load() {
        this->handle = dlopen(this->name.c_str(), RTLD_LAZY);
        if (!this->handle) {
            return std::unexpected{dlerror()};
        }
        return {};
    }

    std::expected<void, std::string> LDDLL::unload() {
        if (!this->handle)
            return std::unexpected{"DLL not loaded"};
        if (dlclose(this->handle) != 0)
            return std::unexpected{dlerror()};
        this->handle = nullptr;
        return {};
    }

    std::string LDDLL::getName() const {
        return this->name;
    }

    template <typename Ret, typename... Args>
    std::expected<std::function<Ret(Args...)>, std::string> LDDLL::getSymbol(std::string symbol) {
        if (!this->handle)
            return std::unexpected{"DLL not loaded"};

        void *symbolPtr = dlsym(this->handle, symbol.c_str());

        if (!symbolPtr) {
            const char *error = dlerror();

            if (error)
                return std::unexpected{error};
            return std::unexpected{"Symbol not found"};
        }

        auto rawFunc = reinterpret_cast<Ret(*)(Args...)>(symbolPtr);

        return std::function<Ret(Args...)>(rawFunc);
    }

    template std::expected<std::function<ArcaTek::Game::IGame *()>, std::string> ArcaTek::DLL::LDDLL::getSymbol<ArcaTek::Game::IGame *>(std::string);
    template std::expected<std::function<ArcaTek::Display::IDisplay *()>, std::string> ArcaTek::DLL::LDDLL::getSymbol<ArcaTek::Display::IDisplay *>(std::string);
} // namespace ArcaTek::DLL

