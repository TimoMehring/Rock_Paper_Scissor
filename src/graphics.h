#pragma once
#include "raylib.h"
struct Graphics{
    Texture2D rock;
    Texture2D paper;
    Texture2D scissor;
};

Graphics LoadGraphics();
void DrawGraphics(Graphics& graphics);