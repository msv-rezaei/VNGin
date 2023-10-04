#include "Game.h" 
#include "InputSystem.h"

#include <stdexcept>

SDL_Window* VNGin::Game::window; 
SDL_Renderer* VNGin::Game::renderer; 

int VNGin::Game::screenWidth; 
int VNGin::Game::screenHeight;
VNGin::ColorRGBA VNGin::Game::backgroundColor; 

bool VNGin::Game::isRunning; 
VNGin::Scene* VNGin::Game::activeScene;

void VNGin::Game::New(std::string title, bool fullScreen, int screenWidth, int screenHeight, ColorRGBA backgroundColor) {
    Game::screenWidth = screenWidth; 
    Game::screenHeight = screenHeight;
    Game::backgroundColor = backgroundColor;

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

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Game::screenWidth, Game::screenHeight, windowFlags);
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
        SDL_GetRendererOutputSize(renderer, &Game::screenWidth, &Game::screenHeight); 
        
    activeScene = new Scene();
}

void VNGin::Game::Run(int rate) {
    isRunning = true; 
    while(true) {
        SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a); 
        SDL_RenderClear(renderer);

        InputSystem::Update();  
        activeScene->Update(renderer);

        SDL_RenderPresent(renderer);

        if(!isRunning) 
            break; 

        SDL_Delay(1000/rate);
    }
}

void VNGin::Game::Stop() {
    isRunning = false;
}

SDL_Texture* VNGin::Game::LoadTexture(const char* path) {
    return IMG_LoadTexture(renderer, path); 
}