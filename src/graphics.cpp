#include "graphics.h"

Graphics LoadGraphics()
{
    Graphics graphics;
    graphics.rock = LoadTexture("assets/rock.png");
    graphics.paper = LoadTexture("assets/paper.png");
    graphics.scissor = LoadTexture("assets/scissor.png");
    graphics.enemy = LoadTexture("assets/enemy.png");

    return graphics;
}

void DrawGraphics(Graphics &graphics, States currentState, PlayerRedRpsPosition &playerRedPos, PlayerBlueRpsPosition playerBluePos,RpsPhase currentPhase, RPSP1 rpsP1)
{
    if (currentState == States::Choice_Rock_Paper_Scissor)
    {
        DrawPlayerRedGraphics(graphics, playerRedPos,currentPhase,rpsP1);
        DrawPlayerBlueGraphics(graphics, playerBluePos);
    }
}

void UnloadGraphics(Graphics &graphics)
{
    UnloadTexture(graphics.rock);
    UnloadTexture(graphics.paper);
    UnloadTexture(graphics.scissor);
    UnloadTexture(graphics.enemy);
}

void DrawPlayerRedGraphics(Graphics &graphics, PlayerRedRpsPosition playerRedPos, RpsPhase currentPhase, RPSP1 rpsP1)
{
    if (currentPhase == RpsPhase::PlayerBlueChoice || currentPhase == RpsPhase::MovePlayerBlue || currentPhase == RpsPhase::PlayerRedAI || currentPhase == RpsPhase::TurnRpsIntoOne){
        DrawTextureEx(graphics.rock, playerRedPos.rockPosPlayerRed, 0.0f, 4.0f, WHITE);
        DrawTextureEx(graphics.paper, playerRedPos.paperPosPlayerRed, 0.0f, 4.0f, WHITE);
        DrawTextureEx(graphics.scissor, playerRedPos.scissorPosPlayerRed, 0.0f, 4.0f, WHITE);
    }
    else if(currentPhase == RpsPhase::MovePlayerRed){
        DrawTextureEx(graphics.enemy,playerRedPos.enemyPosPlayerRed,0.0f, 4.0f,WHITE);
    }
}

void DrawPlayerBlueGraphics(Graphics &graphics, PlayerBlueRpsPosition playerBluePos)
{
    DrawTextureEx(graphics.rock, playerBluePos.rockPosPlayerBlue, 0.0f, 4.0f, WHITE);
    DrawTextureEx(graphics.paper, playerBluePos.paperPosPlayerBlue, 0.0f, 4.0f, WHITE);
    DrawTextureEx(graphics.scissor, playerBluePos.scissorPosPlayerBlue, 0.0f, 4.0f, WHITE);
}
