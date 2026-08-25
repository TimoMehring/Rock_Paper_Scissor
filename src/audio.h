#pragma once
#include "raylib.h"

struct Audio{
    Music Theme;
    Sound ChoiceSound;
    Sound PointWin;
    Sound PlayerWins;
    Sound DrawSound;

};

Audio LoadAudio();
void UnloadAudio(Audio audio);
void PlayAudio(Audio& audio);