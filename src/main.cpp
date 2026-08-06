#include "raylib.h"

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
        DrawText("raylib funktioniert auf dem M2 Pro!", 180, 280, 30, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}