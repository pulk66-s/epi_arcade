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

void SDL2::init(std::shared_ptr<ArcaTek::Event::GameEventManager> gameEventManager, std::shared_ptr<ArcaTek::Event::DisplayEventManager> displayEventManager) {
    this->displayEventManager = displayEventManager;
    this->gameEventManager = gameEventManager;
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
    this->handleEvents();
}

void SDL2::handleEvents() {
    this->displayEventManager->drawSquare->attach([this](ArcaTek::Buffer::Square square) {
        // std::cout << "Drawingj.color.r << " " << (int)square.color.g << " " << (int)square.color.b << " " << (int)square.color.a << std::endl;
        this->drawables.push_back(std::make_shared<ArcaTek::Buffer::Square>(square));
    });
}

void SDL2::clear() {
    this->drawables.clear();
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set background color to black
    SDL_RenderClear(renderer); // Clear with background color
}

void SDL2::render() {
    frameStart = SDL_GetTicks();

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            this->gameEventManager->closeApp->notify(true);
        }
    }

    // Handle multiple keys using keyboard state
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
    
    if (keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_Z]) {
        this->gameEventManager->keyPressed->notify(ArcaTek::Event::Key::Up);
    }
    if (keyboardState[SDL_SCANCODE_S]) {
        this->gameEventManager->keyPressed->notify(ArcaTek::Event::Key::Down);
    }
    if (keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_Q]) {
        this->gameEventManager->keyPressed->notify(ArcaTek::Event::Key::Left);
    }
    if (keyboardState[SDL_SCANCODE_D]) {
        this->gameEventManager->keyPressed->notify(ArcaTek::Event::Key::Right);
    }

    for (std::shared_ptr<ArcaTek::Buffer::IDrawable> drawable : this->drawables) {
        switch (drawable->getType()) {
            case ArcaTek::Buffer::DrawableType::Square:
                ArcaTek::Buffer::Square square = *static_cast<ArcaTek::Buffer::Square*>(drawable.get());
                SDL_Rect rect = {square.pos.x, square.pos.y, square.size.x, square.size.y};
                SDL_SetRenderDrawColor(renderer, square.color.r, square.color.g, square.color.b, square.color.a);
                SDL_RenderFillRect(renderer, &rect);
                break;
        }
    }
    SDL_RenderPresent(renderer);

    // Frame rate control
    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < FRAME_DELAY) {
        SDL_Delay(FRAME_DELAY - frameTime);
    }
}

extern "C" {
    SDL2 *createDisplay() {
        return new SDL2();
    }
}
