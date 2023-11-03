#include "InputSystem.h"
#include "Game.h"

#include <stdexcept>
#include <algorithm>

std::map<SDL_Scancode, VNGin::KeyState> VNGin::InputSystem::keyMap;

bool VNGin::InputSystem::GetKey(SDL_Scancode code) {
    auto iter = FindOrAddKey(code);
    return iter->second.currentState;
}

bool VNGin::InputSystem::GetKeyDown(SDL_Scancode code) {
    auto iter = FindOrAddKey(code);
    return iter->second.lastState == false && iter->second.currentState == true;
}

bool VNGin::InputSystem::GetKeyUp(SDL_Scancode code) {
    auto iter = FindOrAddKey(code);
    return iter->second.lastState == true && iter->second.currentState == false;
}

VNGin::Vector VNGin::InputSystem::GetMousePosition() {
    int mx, my;
    SDL_GetMouseState(&mx, &my); 
    return Vector(mx, my);
}

std::map<SDL_Scancode, VNGin::KeyState>::iterator VNGin::InputSystem::FindOrAddKey(SDL_Scancode code) {
    auto iter = keyMap.find(code);
    if(iter == keyMap.end()) {
        iter = keyMap.insert({code, {false, false}}).first; 
        Update(); 
    }

    return iter;
}

void VNGin::InputSystem::UpdateMap(SDL_Scancode code, bool value) {
    try {
        keyMap.at(code).lastState = keyMap.at(code).currentState;
        keyMap.at(code).currentState = value;
    }
    catch(std::out_of_range e) { return; }
}

void VNGin::InputSystem::Update() {
    SDL_Event event; 

    for(auto &key : keyMap) {
        key.second.lastState = key.second.currentState;
    }

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
        case SDL_QUIT: 
            Game::Quit();
            exit(0); 
            break;
        case SDL_KEYDOWN: 
            UpdateMap(event.key.keysym.scancode, true); 
            break; 
        case SDL_KEYUP: 
            UpdateMap(event.key.keysym.scancode, false); 
            break; 
        default: 
            break;
        }
    }
}