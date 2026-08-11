#pragma once
#include "raylib.h"
#include "states.h"
struct Graphics{
    Texture2D rock;
    Texture2D paper;
    Texture2D scissor;
    Texture2D enemy;
};

Graphics LoadGraphics();
void DrawGraphics(Graphics& graphics, States currentState);
void UnloadGraphics(Graphics& graphics);
void DrawPlayerRedGraphics(Graphics& graphics);
void DrawPlayerBlueGraphics(Graphics& graphics);