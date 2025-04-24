#include "SDL2.hpp"
#include "Core/Buffer/Square.hpp"
#include <SDL2/SDL.h>
#include <iostream>

SDL2::SDL2() : window(nullptr), renderer(nullptr){}

SDL2::~SDL2() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDL2::init(ArcaTek::Event::DisplayEventManager &eventManager) {
    this->eventManager = std::make_unique<ArcaTek::Event::DisplayEventManager>(eventManager);
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow("SDL2 Display", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return;
    }
}

void SDL2::render(ArcaTek::Buffer::DisplayBuffer &buffer) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            this->eventManager->closeApp->notify(true);
        }
    }

    SDL_RenderClear(renderer);

    std::vector<std::shared_ptr<ArcaTek::Buffer::IDrawable>> drawables = buffer.getDrawables();

    for (std::shared_ptr<ArcaTek::Buffer::IDrawable> drawable : drawables) {
        if (std::dynamic_pointer_cast<ArcaTek::Buffer::Square>(drawable)) {
            std::shared_ptr<ArcaTek::Buffer::Square> square = std::dynamic_pointer_cast<ArcaTek::Buffer::Square>(drawable);

            SDL_Rect rect = {square->pos.x, square->pos.y, square->size.x, square->size.y};
            SDL_RenderFillRect(renderer, &rect);
        }
    }
    SDL_RenderPresent(renderer);
}

extern "C" {
    SDL2 *createDisplay() {
        return new SDL2();
    }
}
