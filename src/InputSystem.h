#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

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
        static int GetKey(SDL_Scancode code);
        static int GetKeyDown(SDL_Scancode code);

        static void AddCallback(SDL_Scancode code, void(*callback)(bool)); 
        static void RemoveCallback(SDL_Scancode code, void(*callback)(bool));
    private: 
        static void Update(void);
        static void UpdateMap(SDL_Scancode event, bool value);
        static std::map<SDL_Scancode, KeyState> keyMap;
        static std::map<SDL_Scancode, std::vector<void(*)(bool)>> callbackMap;
    };
}

#endif