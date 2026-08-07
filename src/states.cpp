#include "states.h"
#include "raylib.h"

void DrawChoicePaperRock(){
    ClearBackground(GREEN);
    DrawText("Paper Wins", 100, 100, 30, WHITE);
}

void DrawChoicePaperPaper(){
    ClearBackground(BLUE);
    DrawText("Draw", 100, 100, 30, WHITE);
}