#include "raylib.h"
#include "states.h"
#include "player.h"
#include "gameplay.h"
#include "graphics.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    RPSP1 rpsP1 = RPSP1::Paper;
    RPSP2 rpsP2 = RPSP2::Rock;

    InitWindow(screenWidth, screenHeight, "RPS");

    SetTargetFPS(60);

    Graphics graphics = LoadGraphics();
    States currentState = States::Choice_Rock_Paper_Scissor;

    PlayerRedRpsPosition playerRedPos;
    PlayerBlueRpsPosition playerBluePos;

    while (!WindowShouldClose())
    {
        UpdatePlayerBlueChoice(rpsP2, graphics,playerBluePos);

        BeginDrawing();

        ClearBackground(DARKBLUE);
        DrawGraphics(graphics,currentState, playerRedPos, playerBluePos);
        
        //CheckResult(rpsP1,rpsP2); //paused for "DrawGraphics" tests

        EndDrawing();
    }
    UnloadGraphics(graphics);

    CloseWindow();

    return 0;
}