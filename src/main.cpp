#include "raylib.h"
#include "states.h"
#include "player.h"
#include "gameplay.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    RPSP1 rpsP1 = RPSP1::Paper;
    RPSP2 rpsP2 = RPSP2::Paper;

    InitWindow(screenWidth, screenHeight, "Test Window");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKBLUE);

        if(rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Rock){
            DrawChoicePaperRock();
        }else if(rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Scissor){
            // Draw
        }else if(rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Paper){
            //Draw 
        }
        
        else if(rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Paper){ // Result = Draw
            DrawChoicePaperPaper();
        }else if(rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Rock){
            //Draw Result = Draw
        }else if(rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Scissor){
            //Draw Result = Draw
        }
        else if(rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Paper){ // Result = P1 
            // Draw P1 Loose
        }else if(rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Rock){
            // Draw P1 Loose
        }else if(rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Scissor){
            // Draw P1 Loose
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}