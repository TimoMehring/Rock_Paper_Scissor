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
    graphics.redPlayer = LoadTexture("assets/playerRed.png");
    graphics.bluePlayer = LoadTexture("assets/playerBlue.png");
    graphics.countZero = LoadTexture("assets/zero.png");
    graphics.countOne = LoadTexture("assets/one.png");
    graphics.countTwo = LoadTexture("assets/two.png");
    graphics.countThree = LoadTexture("assets/three.png");
    graphics.bestOfFive = LoadTexture("assets/bestoffive.png");
    graphics.draw = LoadTexture("assets/draw.png");
    graphics.arrow = LoadTexture("assets/arrow.png");
    graphics.redWins = LoadTexture("assets/redwins.png");
    graphics.blueWins = LoadTexture("assets/bluewins.png");

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
    UnloadTexture(graphics.bestOfFive);
    UnloadTexture(graphics.draw);
    UnloadTexture(graphics.arrow);
    
    UnloadTexture(graphics.redPlayer);
    UnloadTexture(graphics.bluePlayer);

    UnloadTexture(graphics.countZero);
    UnloadTexture(graphics.countOne);
    UnloadTexture(graphics.countTwo);
    UnloadTexture(graphics.countThree);

    UnloadTexture(graphics.redWins);
    UnloadTexture(graphics.blueWins);
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
    DrawTexture(graphics.battleArea,360,140,WHITE); // height 130
    DrawTextureEx(graphics.bestOfFive,{700.0f,480.0f},0.0f,4.0f,WHITE); // 30, 255
    DrawTextureEx(graphics.redPlayer,{30.0f,30.0f},0.0f,5.0f,WHITE);
    DrawTextureEx(graphics.bluePlayer,{30.0f,470.0f},0.0f,5.0f,WHITE);
}

void DrawCount(Graphics& graphics,int redWinCount,int blueWinCount){
    TraceLog(LOG_INFO,"Red Count: %d | Blue Count: %d",redWinCount,blueWinCount);
    if(redWinCount == 0){
        DrawTextureEx(graphics.countZero,{40.0f,140.0f},0.0f,7.0f,WHITE);
    }
    else if(redWinCount == 1){
        DrawTextureEx(graphics.countOne,{40.0f,140.0f},0.0f,7.0f,WHITE);
    }
    else if(redWinCount == 2){
        DrawTextureEx(graphics.countTwo,{40.0f,140.0f},0.0f,7.0f,WHITE);
    }
    else if(redWinCount == 3){
        DrawTextureEx(graphics.countThree,{40.0f,140.0f},0.0f,7.0f,WHITE);
    }

    if(blueWinCount == 0){
        DrawTextureEx(graphics.countZero,{40.0f,370.0f},0.0f,7.0f,WHITE);
    }
    else if(blueWinCount == 1){
        DrawTextureEx(graphics.countOne,{40.0f,370.0f},0.0f,7.0f,WHITE);
    }
    else if(blueWinCount == 2){
        DrawTextureEx(graphics.countTwo,{40.0f,370.0f},0.0f,7.0f,WHITE);
    }
    else if(blueWinCount == 3){
        DrawTextureEx(graphics.countThree,{40.0f,370.0f},0.0f,7.0f,WHITE);
    }
}