#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

#include <map>

namespace VNGin {
    class Game;
    class InputSystem {
        friend class Game; 
    public: 
        static int GetKey(SDL_Scancode code);
    private: 
        static void Update(void);
        static void UpdateMap(SDL_KeyboardEvent* event, bool value);
        static std::map<SDL_Scancode, bool> keyMap;
    };
}

#endif