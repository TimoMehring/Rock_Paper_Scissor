#include "states.h"
#include "raylib.h"
//P1 Win
void DrawChoicePaperRock(){
    ClearBackground(GREEN);
    DrawText("Paper Wins", 100, 100, 30, WHITE);
}

void DrawChoiceRockScissor(){
        ClearBackground(GREEN);
        DrawText("Rock Wins", 100, 100, 30, WHITE);
}

void DrawChoiceScissorPaper(){
        ClearBackground(GREEN);
        DrawText("Scissor Wins", 100, 100, 30, WHITE);
}
// P1 Draw P2
void DrawChoicePaperPaper(){
    ClearBackground(BLUE);
    DrawText("Draw", 100, 100, 30, WHITE);
}
void DrawChoiceRockRock(){
    ClearBackground(BLUE);
    DrawText("Draw", 100, 100, 30, WHITE);

}
void DrawChoiceScissorScissor(){
    ClearBackground(BLUE);
    DrawText("Draw", 100, 100, 30, WHITE);
}

void DrawChoiceRockPaper(){
    ClearBackground(BLUE);
    DrawText("Paper wins", 100, 100, 30, WHITE);
}

void DrawChoiceScissorRock(){
    ClearBackground(BLUE);
    DrawText("Rock wins", 100, 100, 30, WHITE);
}

void DrawChoicePaperScissor(){
    ClearBackground(BLUE);
    DrawText("Scissor wins", 100, 100, 30, WHITE);
}




