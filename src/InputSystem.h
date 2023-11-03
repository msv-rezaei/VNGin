#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

#include "Vector.h"

#include <vector> 
#include <map>

namespace VNGin {
    class Game;

    struct KeyState {
    public: 
        bool lastState; 
        bool currentState;
    };

    class InputSystem {
        friend class Game; 
    public: 
        static bool GetKey(SDL_Scancode code);
        static bool GetKeyDown(SDL_Scancode code);
        static bool GetKeyUp(SDL_Scancode code);
        static Vector GetMousePosition(void);
    private: 
        static std::map<SDL_Scancode, KeyState>::iterator FindOrAddKey(SDL_Scancode code);

        static void Update(void);
        static void UpdateMap(SDL_Scancode event, bool value);
        static std::map<SDL_Scancode, KeyState> keyMap;
    };
}

#endif