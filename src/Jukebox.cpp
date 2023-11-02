#include "Jukebox.h"

Mix_Music* VNGin::Jukebox::music;

void VNGin::Jukebox::Set(Mix_Music* music) {
    Jukebox::music = music;
}

void VNGin::Jukebox::Play() {
    if(Mix_PlayingMusic() == 0) {
        Mix_PlayMusic(Jukebox::music, -1);
    }
    else if(Mix_PausedMusic() == 1) {
            Mix_ResumeMusic();
    }
}

void VNGin::Jukebox::Pause() {
    Mix_PauseMusic();
}