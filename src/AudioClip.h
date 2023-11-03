#ifndef AUDIOCLIP_H
#define AUDIOCLIP_H

#include "Game.h"
#include <SDL2/SDL_mixer.h>

namespace VNGin {
    class AudioClip {
    public: 
        AudioClip(const char* path) : clip{Game::LoadSFX(path)} {} 
        ~AudioClip() { Mix_FreeChunk(clip); }
        void Play() { Mix_PlayChannel(-1, clip, 0); }
    private: 
        Mix_Chunk* clip;
    };
}

#endif