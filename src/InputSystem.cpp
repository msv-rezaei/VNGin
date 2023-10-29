#include "InputSystem.h"

#include <stdexcept>
#include <algorithm>

std::map<SDL_Scancode, VNGin::KeyState> VNGin::InputSystem::keyMap;
std::map<SDL_Scancode, std::vector<void(*)(bool)>> VNGin::InputSystem::callbackMap;

int VNGin::InputSystem::GetKey(SDL_Scancode code) {
    auto iter = keyMap.find(code);
    if(iter == keyMap.end()) {
        iter = keyMap.insert({code, {false, false}}).first; 
        Update(); 
    }

    return iter->second.currentState;
}

int VNGin::InputSystem::GetKeyDown(SDL_Scancode code) {
    auto iter = keyMap.find(code);
    if(iter == keyMap.end()) {
        iter = keyMap.insert({code, {false, false}}).first; 
        Update(); 
    }
    
    return iter->second.lastState == false && iter->second.currentState == true;
}

void VNGin::InputSystem::AddCallback(SDL_Scancode code, void(*callback)(bool)) {
    auto iter = callbackMap.find(code); 
    if(iter != callbackMap.end()) {
        iter->second.push_back(callback);
        return; 
    }

    callbackMap.insert({code, {callback}});
}

void VNGin::InputSystem::RemoveCallback(SDL_Scancode code, void(*callback)(bool)) {
    auto iter = callbackMap.find(code); 
    if(iter != callbackMap.end()) {
        auto vecIter = std::find(iter->second.begin(), iter->second.end(), callback);
        if(vecIter != iter->second.end()) 
            iter->second.erase(vecIter);
    }
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
            exit(0); 
            break;
        case SDL_KEYDOWN: 
            for(auto callback : callbackMap[event.key.keysym.scancode]) callback(true);
            UpdateMap(event.key.keysym.scancode, true); 
            break; 
        case SDL_KEYUP: 
            for(auto callback : callbackMap[event.key.keysym.scancode]) callback(false);
            UpdateMap(event.key.keysym.scancode, false); 
            break; 
        default: 
            break;
        }
    }
}