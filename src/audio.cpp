#include "audio.h"

Audio LoadAudio(){
    Audio audio;
    audio.Theme = LoadMusicStream("assets/themerps.wav");

    audio.ChoiceSound = LoadSound("assets/choicesound.wav");
    audio.PointWin = LoadSound("assets/pointwin.wav");
    audio.PlayerWins = LoadSound("assets/playerwins.wav");
    audio.DrawSound = LoadSound("assets/drawsound.wav");

    return audio;
}

void UnloadAudio(Audio audio){
    UnloadMusicStream(audio.Theme);

    UnloadSound(audio.ChoiceSound);
    UnloadSound(audio.PointWin);
    UnloadSound(audio.PlayerWins);
    UnloadSound(audio.DrawSound);
}

/* void PlayAudio(Audio& audio){
    PlayMusicStream(audio.Theme);
    UpdateMusicStream(audio.Theme);
} */