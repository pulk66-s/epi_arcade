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
        std::shared_ptr<ArcaTek::Event::DisplayEventManager> displayEventManager = nullptr;
        std::shared_ptr<ArcaTek::Event::GameEventManager> gameEventManager = nullptr;
        std::vector<std::shared_ptr<ArcaTek::Buffer::IDrawable>> drawables = {};
        const int FPS = 60;
        const int FRAME_DELAY = 1000 / FPS;
        Uint32 frameStart = 0;
        int frameTime = 0;

    public:
        SDL2();
        ~SDL2();

        void init(std::shared_ptr<ArcaTek::Event::GameEventManager> eventManager, std::shared_ptr<ArcaTek::Event::DisplayEventManager> displayEventManager);
        void render() override;
        void clear() override;

    private:
        void handleEvents();
};
