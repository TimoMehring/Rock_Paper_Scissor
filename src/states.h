#pragma once
#include "raylib.h"

enum class States{
  Startscreen,
  Choice_Rock_Paper_Scissor,
  

};

enum class WinLooe{
  Win,
  Lose,
};

void UpdateChoicePaperRock();
void DrawChoicePaperRock();