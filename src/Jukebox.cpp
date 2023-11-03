#include "Jukebox.h"
#include "Game.h"

Mix_Music* VNGin::Jukebox::music;

void VNGin::Jukebox::Set(const char* path) {
    if(music != NULL) 
        Mix_FreeMusic(music);

    music = Game::LoadMusic(path);
}

void VNGin::Jukebox::Play() {
    if(Mix_PlayingMusic() == 0) {
        Mix_PlayMusic(music, -1);
    }
    else if(Mix_PausedMusic() == 1) {
            Mix_ResumeMusic();
    }
}

void VNGin::Jukebox::Pause() {
    Mix_PauseMusic();
}