#ifndef GAME_H  
#define GAME_H

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 

#include <string> 

namespace VNGin {
    class Game {
    public: 
        Game(std::string title = "New Game", bool fullScreen = true, int screenWidth = 1920, int screenHeight = 1080); 

        void Run(int rate);
        //void Stop(void);  
    private: 
        SDL_Window* window;
        SDL_Renderer* renderer;

        int screenWidth;
        int screenHeight;

        bool isRunning; 
    };
}

#endif

