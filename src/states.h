#pragma once
#include "raylib.h"

enum class States{
  Startscreen,
  Choice_Rock_Paper_Scissor,
  ResultPending
  

};

enum class WinLooe{
  Win,
  Lose,
};

void UpdateChoicePaperRock();
void DrawChoicePaperRock();
void DrawChoicePaperPaper();