#pragma once
#include "raylib.h"
#include "states.h"
#include "player.h"

struct Graphics{
    Texture2D rock;
    Texture2D paper;
    Texture2D scissor;
    Texture2D enemy;

    Texture2D battleArea;
    Texture2D background;
    Texture2D bestOfFive;
    Texture2D draw;
    Texture2D arrow;

    Texture2D redPlayer;
    Texture2D bluePlayer;

    Texture2D countZero;
    Texture2D countOne;
    Texture2D countTwo;
    Texture2D countThree;

    Texture2D redWins;
    Texture2D blueWins;

    Texture2D volumeIcon;
    Texture2D volumeIconMuted;
};

Graphics LoadGraphics();
void UnloadGraphics(Graphics& graphics);
void DrawPlayerRedRPS(Graphics& graphics,PlayerRedRpsPosition playerRedPos,RpsPhase currentPhase,RPSP1 rpsP1);
void DrawPlayerBlueRPS(Graphics& graphics,PlayerBlueRpsPosition playerBluePos);
void DrawGraphicsPlayerBlue(Graphics &graphics,PlayerBlueRpsPosition playerBluePos);
void DrawGraphicsPlayerRed(Graphics &graphics,PlayerRedRpsPosition &playerRedPos,RpsPhase currentPhase,RPSP1 rpsP1);
void DrawPlayground(Graphics& graphics);
void DrawCount(Graphics& graphics,int redWinCount,int blueWinCount);
void DrawVolumeSection(Graphics& graphics, bool& volumeMuted);
