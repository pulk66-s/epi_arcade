#pragma once

#include "Core/Display/IDisplay.hpp"
#include "Core/Buffer/DisplayBuffer.hpp"

#include <memory>
#include <SDL2/SDL.h>

class SDL2 : public ArcaTek::Display::IDisplay {
public:
    SDL2();
    ~SDL2();

    void init() override;
    void render(ArcaTek::Buffer::DisplayBuffer &buffer) override;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
};
