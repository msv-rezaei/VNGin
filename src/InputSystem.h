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
        static bool GetMouseButton(int index);
        static bool GetKeyDown(SDL_Scancode code);
        static bool GetMouseButtonDown(int index);
        static bool GetKeyUp(SDL_Scancode code);
        static bool GetMouseButtonUp(int index);
        static Vector GetMousePosition(void);
    private: 
        static std::map<SDL_Scancode, KeyState>::iterator FindOrAddKey(SDL_Scancode code);

        static void Update(void);
        static void UpdateMap(SDL_Scancode event, bool value);
        static void UpdateMouseState(int buttonIndex, bool value);
        static std::map<SDL_Scancode, KeyState> keyMap;
        static std::vector<KeyState> mouseButtons;
    };
}

#endif