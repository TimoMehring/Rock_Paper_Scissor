#include "graphics.h"

Graphics LoadGraphics()
{
    Graphics graphics;
    graphics.rock = LoadTexture("assets/rock.png");
    graphics.paper = LoadTexture("assets/paper.png");
    graphics.scissor = LoadTexture("assets/scissor.png");
    graphics.enemy = LoadTexture("assets/enemy.png");
    graphics.battleArea = LoadTexture("assets/battlearea.png");
    graphics.background = LoadTexture("assets/background.png");

    return graphics;
}

void DrawGraphicsPlayerBlue(Graphics &graphics,PlayerBlueRpsPosition playerBluePos){
    DrawPlayerBlueRPS(graphics, playerBluePos);
}

void DrawGraphicsPlayerRed(Graphics &graphics,PlayerRedRpsPosition& playerRedPos,RpsPhase currentPhase, RPSP1 rpsP1){
    DrawPlayerRedRPS(graphics, playerRedPos,currentPhase, rpsP1);
}

void UnloadGraphics(Graphics &graphics)
{
    UnloadTexture(graphics.rock);
    UnloadTexture(graphics.paper);
    UnloadTexture(graphics.scissor);
    UnloadTexture(graphics.enemy);

    UnloadTexture(graphics.battleArea);
    UnloadTexture(graphics.background);
}

void DrawPlayerRedRPS(Graphics &graphics, PlayerRedRpsPosition playerRedPos, RpsPhase currentPhase, RPSP1 rpsP1)
{
    if (currentPhase == RpsPhase::PlayerBlueChoice || currentPhase == RpsPhase::MovePlayerBlue || currentPhase == RpsPhase::PlayerRedAI || currentPhase == RpsPhase::TurnRpsIntoOne){
        DrawTextureEx(graphics.rock, playerRedPos.rockPosPlayerRed, 0.0f, 4.0f, WHITE);
        DrawTextureEx(graphics.paper, playerRedPos.paperPosPlayerRed, 0.0f, 4.0f, WHITE);
        DrawTextureEx(graphics.scissor, playerRedPos.scissorPosPlayerRed, 0.0f, 4.0f, WHITE);
    }
    else if(currentPhase == RpsPhase::MovePlayerRed){
        DrawTextureEx(graphics.enemy,playerRedPos.enemyPosPlayerRed,0.0f, 4.0f,WHITE);
    }
    else if(currentPhase == RpsPhase::RevealPlayerRed || currentPhase == RpsPhase::ShowResult){
        if(rpsP1 == RPSP1::Rock){
            DrawTextureEx(graphics.rock, playerRedPos.enemyPosPlayerRed, 0.0f, 4.0f, WHITE);
        }
        else if(rpsP1 == RPSP1::Paper){
             DrawTextureEx(graphics.paper, playerRedPos.enemyPosPlayerRed, 0.0f, 4.0f, WHITE);
        }
        else if(rpsP1 == RPSP1::Scissor){
             DrawTextureEx(graphics.scissor, playerRedPos.enemyPosPlayerRed, 0.0f, 4.0f, WHITE);
        }
    }
}

void DrawPlayerBlueRPS(Graphics &graphics, PlayerBlueRpsPosition playerBluePos)
{
    DrawTextureEx(graphics.rock, playerBluePos.rockPosPlayerBlue, 0.0f, 4.0f, WHITE);
    DrawTextureEx(graphics.paper, playerBluePos.paperPosPlayerBlue, 0.0f, 4.0f, WHITE);
    DrawTextureEx(graphics.scissor, playerBluePos.scissorPosPlayerBlue, 0.0f, 4.0f, WHITE);
}


void DrawPlayground(Graphics& graphics){
    DrawTexture(graphics.background,0,0,WHITE);
    DrawTexture(graphics.battleArea,360,130,WHITE);
}