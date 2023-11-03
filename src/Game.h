#ifndef GAME_H  
#define GAME_H

#include "Utility.h"
#include "Scene.h"

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_mixer.h>

#include <string> 

namespace VNGin {
    class Game {
    public: 
        static void New(std::string title = "New Game", bool fullScreen = true, int screenWidth = 1920, int screenHeight = 1080, 
            ColorRGBA backgroundColor = ColorRGBA::white); 
        
        static void Quit(void);

        static void Run(int rate);
        static void Stop(void);  

        static int ScreenWidth() { return screenWidth; }
        static int ScreenHeight() { return screenHeight; }
        static ColorRGBA BackgroundColor() { return backgroundColor; } 
        static bool IsRunning() { return isRunning; }
        static Scene* GetActiveScene() { return activeScene; }

        static SDL_Texture* LoadTexture(const char* path);
        static Mix_Music* LoadMusic(const char* path); 
        static Mix_Chunk* LoadSFX(const char* path);
    private: 
        static SDL_Window* window;
        static SDL_Renderer* renderer;

        static int screenWidth;
        static int screenHeight;
        static ColorRGBA backgroundColor;

        static bool isRunning; 
        static Scene* activeScene;
    };
}

#endif

