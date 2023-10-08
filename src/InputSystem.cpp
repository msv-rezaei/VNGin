#include "InputSystem.h"

#include <algorithm>

std::map<SDL_Scancode, bool> VNGin::InputSystem::keyMap;
std::map<SDL_Scancode, std::vector<void(*)(bool)>> VNGin::InputSystem::callbackMap;

int VNGin::InputSystem::GetKey(SDL_Scancode code) {
    auto iter = keyMap.find(code);
    if(iter == keyMap.end()) {
        iter = keyMap.insert({code, false}).first; 
        Update(); 
    }

    return iter->second;
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
            for(auto callback : callbackMap[event.key.keysym.scancode]) callback(true);
            UpdateMap(&event.key, true); 
            break; 
        case SDL_KEYUP: 
            for(auto callback : callbackMap[event.key.keysym.scancode]) callback(false);
            UpdateMap(&event.key, false); 
            break; 
        default: 
            break;
        }
    }
}