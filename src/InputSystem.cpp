#include "InputSystem.h"

#include <algorithm>

std::map<SDL_Scancode, bool> VNGin::InputSystem::keyMap;

int VNGin::InputSystem::GetKey(SDL_Scancode code) {
    auto iter = keyMap.find(code);
    if(iter == keyMap.end()) {
        iter = keyMap.insert({code, false}).first; 
        Update(); 
    }

    return iter->second;
}

void VNGin::InputSystem::UpdateMap(SDL_KeyboardEvent* event, bool value) {
    if(!event->repeat) {
        for(auto& key : keyMap) {
            if(event->keysym.scancode == key.first) 
                key.second = value;
        }
    }
}

void VNGin::InputSystem::Update() {
    SDL_Event event; 

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
        case SDL_QUIT: 
            exit(0); 
            break;
        case SDL_KEYDOWN: 
            UpdateMap(&event.key, true); 
            break; 
        case SDL_KEYUP: 
            UpdateMap(&event.key, false); 
            break; 
        default: 
            break;
        }
    }
}