#ifndef JUKEBOX_H
#define JUKEBOX_H

#include <SDL2/SDL_mixer.h>

namespace VNGin {
    class Jukebox {
    public: 
        static void Set(Mix_Music* music);
        static void Play(void);
        static void Pause(void);
    private: 
        static Mix_Music* music;
    };
}

#endif