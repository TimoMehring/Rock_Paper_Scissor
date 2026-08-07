#include "raylib.h"
#include "states.h"
#include "player.h"
#include "gameplay.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    RPSP1 rpsP1 = RPSP1::Paper;
    RPSP2 rpsP2 = RPSP2::Rock;

    InitWindow(screenWidth, screenHeight, "Test Window");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKBLUE);

        CheckResult(rpsP1,rpsP2);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}