#pragma once
#include "raylib.h"

struct Audio{
    Music Theme;
    Sound ChoiceSound;

};

Audio LoadAudio();
void UnloadAudio(Audio audio);
void PlayAudio(Audio& audio);