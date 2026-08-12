#include "raylib.h"
#include "states.h"
#include "player.h"
#include "gameplay.h"
#include "graphics.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    RPSP1 rpsP1 = RPSP1::Paper;
    RPSP2 rpsP2 = RPSP2::Rock;

    InitWindow(screenWidth, screenHeight, "RPS");

    SetTargetFPS(60);

    Graphics graphics = LoadGraphics();
    States currentState = States::Choice_Rock_Paper_Scissor;

    PlayerRedRpsPosition playerRedPos;
    PlayerBlueRpsPosition playerBluePos;

    RpsPhase currentPhase = RpsPhase::PlayerBlueChoice;

    float resultTimer = 0.0f;

    int blueWinCount = 0;
    int redWinCount = 0;

    while (!WindowShouldClose())
    {
        UpdatePlayerBlueChoice(rpsP2, graphics,playerBluePos, currentPhase);
        if(currentPhase == RpsPhase::PlayerRedAI){
            UpdatePlayerRedAI(rpsP1, playerRedPos, currentPhase);
        }
        if(currentPhase == RpsPhase::TurnRpsIntoOne){
            UpdateTurnPlayerRedIntoBack(playerRedPos,currentPhase);
        }
        if(currentPhase == RpsPhase::MovePlayerRed){
            UpdatePlayerRedMovement(playerRedPos, currentPhase,rpsP1);
        }
        if(currentPhase == RpsPhase::RevealPlayerRed){
            UpdateRevealPlayerRed(currentPhase);
        }
        if(currentPhase == RpsPhase::ShowResult){
            bool isDraw = ((rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Rock) || (rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Paper) ||  (rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Scissor));
            if(isDraw){
                resultTimer += GetFrameTime();
                if(resultTimer  >= 1.0f){
                    resultTimer = 0.0f;
                    ResetRound(playerBluePos, playerRedPos, currentPhase);
                }
            }
            bool redWins =((rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Rock) || (rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Scissor) || (rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Paper));
            if(redWins){
                resultTimer += GetFrameTime();
                if(resultTimer  >= 1.0f){
                    resultTimer = 0.0f;
                    redWinCount++;
                    TraceLog(LOG_INFO, "Red Wins: %d", redWinCount);
                    ResetRound(playerBluePos, playerRedPos, currentPhase);
                }
            }
            bool blueWins =((rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Paper) || (rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Rock) || (rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Scissor));
            if(blueWins){
                resultTimer += GetFrameTime();
                if(resultTimer  >= 1.0f){
                    resultTimer = 0.0f;
                    blueWinCount++;
                    TraceLog(LOG_INFO, "Blue Wins: %d", blueWinCount);
                    ResetRound(playerBluePos, playerRedPos, currentPhase);
                }
            }
        }
        BeginDrawing();

        ClearBackground(DARKBLUE);
        DrawPlayground(graphics);

        DrawCount(graphics,redWinCount,blueWinCount);
        
        
        DrawGraphicsPlayerBlue(graphics,playerBluePos);
        DrawGraphicsPlayerRed(graphics,playerRedPos,currentPhase,rpsP1);
        if(currentPhase == RpsPhase::ShowResult){
            CheckResult(rpsP1,rpsP2);
        }
        

        EndDrawing();
    }
    UnloadGraphics(graphics);

    CloseWindow();

    return 0;
}