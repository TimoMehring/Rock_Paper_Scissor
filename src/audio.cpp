#include "audio.h"

Audio LoadAudio(){
    Audio audio;
    audio.Theme = LoadMusicStream("assets/themerps.wav");
    audio.ChoiceSound = LoadSound("assets/choicesound.wav");

    return audio;
}

void UnloadAudio(Audio audio){
    UnloadMusicStream(audio.Theme);

    UnloadSound(audio.ChoiceSound);
}

void PlayAudio(Audio& audio){
    PlayMusicStream(audio.Theme);
    UpdateMusicStream(audio.Theme);
}