#include "Game.h" 

#include <stdexcept>

VNGin::Game::Game(std::string title, bool fullScreen, int screenWidth, int screenHeight) {
    int windowFlags = fullScreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;
    int rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::string msg = "SDL failed to initialize. SDL_Error: ";
        msg += SDL_GetError(); 
        throw new std::runtime_error(msg); 
    }    
    if(!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) {
        std::string msg = "SDL_image failed to initialize. IMG_Error: "; 
        msg += IMG_GetError(); 
        throw new std::runtime_error(msg); 
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, windowFlags);
    if(!window) {
        std::string msg = "SDL failed to create window. SDL_Error: "; 
        msg += SDL_GetError(); 
        throw new std::runtime_error(msg);
    }

    renderer = SDL_CreateRenderer(window, -1, rendererFlags); 
    if(!renderer) {
        std::string msg = "SDL failed to create renderer context. SDL_Error: "; 
        msg += SDL_GetError(); 
        throw new std::runtime_error(msg);
    }

    if(fullScreen) 
        SDL_GetRendererOutputSize(renderer, &this->screenWidth, &this->screenHeight); 
    else {
        this->screenWidth = screenWidth;
        this->screenHeight = screenHeight;
    }
}

void VNGin::Game::Run(int rate) {
    isRunning = true; 
    while(true) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
        SDL_RenderClear(renderer);

        // Logic Update

        SDL_RenderPresent(renderer);
        SDL_Delay(1000/rate);
    }
}