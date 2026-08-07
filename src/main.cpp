#include "raylib.h"
#include "stab.h"
#include "player.h"
#include "gameplay.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Test Window");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKBLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}