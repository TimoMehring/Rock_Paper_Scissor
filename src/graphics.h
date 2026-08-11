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
void DrawGraphics(Graphics& graphics, States currentState,PlayerRedRpsPosition& playerRedPos,PlayerBlueRpsPosition playerBluePos,RpsPhase currentPhase, RPSP1 rpsP1);
void UnloadGraphics(Graphics& graphics);
void DrawPlayerRedGraphics(Graphics& graphics,PlayerRedRpsPosition playerRedPos,RpsPhase currentPhase,RPSP1 rpsP1);
void DrawPlayerBlueGraphics(Graphics& graphics,PlayerBlueRpsPosition playerBluePos);
//void DrawPlayerRedGraphics(Graphics& graphics,PlayerRedRpsPosition& playerRedPos,RpsPhase currentPhase,RPSP1 rpsP1);
