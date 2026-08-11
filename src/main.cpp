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

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKBLUE);
        DrawTexture(graphics.rock, 300, 300, WHITE); // Test
        
        CheckResult(rpsP1,rpsP2);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}