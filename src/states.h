#pragma once
#include "raylib.h"

enum class States{
  Startscreen,
  Choice_Rock_Paper_Scissor,
  ResultPending,
  CheckingWinner

};


enum class WinLose{
  Win,
  Lose,
};
//P1 Win
void UpdateChoicePaperRock();
void DrawChoicePaperRock(); 
void DrawChoiceRockScissor();
void DrawChoiceScissorPaper();
// P1 Draw P2
void DrawChoicePaperPaper();
void DrawChoiceRockRock();
void DrawChoiceScissorScissor();
//P2 Win
void DrawChoiceRockPaper();
void DrawChoiceScissorRock();
void DrawChoicePaperScissor();