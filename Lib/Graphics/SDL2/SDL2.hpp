#pragma once

#include "Core/Display/IDisplay.hpp"
#include "Core/Buffer/DisplayBuffer.hpp"
#include "Core/Event/DisplayEventManager.hpp"

#include <memory>
#include <SDL2/SDL.h>

class SDL2 : public ArcaTek::Display::IDisplay {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *texture;
        std::unique_ptr<ArcaTek::Event::DisplayEventManager> eventManager = nullptr;

    public:
        SDL2();
        ~SDL2();

        void init(ArcaTek::Event::DisplayEventManager &eventManager) override;
        void render(ArcaTek::Buffer::DisplayBuffer &buffer) override;
};
