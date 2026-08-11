#pragma once
#include "raylib.h"
#include "states.h"
#include "player.h"
struct Graphics{
    Texture2D rock;
    Texture2D paper;
    Texture2D scissor;
    Texture2D enemy;
};

Graphics LoadGraphics();
void DrawGraphics(Graphics& graphics, States currentState,PlayerRedRpsPosition& playerRedPos,PlayerBlueRpsPosition playerBluePos);
void UnloadGraphics(Graphics& graphics);
void DrawPlayerRedGraphics(Graphics& graphics,PlayerRedRpsPosition playerRedPos);
void DrawPlayerBlueGraphics(Graphics& graphics,PlayerBlueRpsPosition playerBluePos);