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

    bool resultCounted = false;

    bool isDraw = false;
    bool redWins = false;
    bool blueWins = false;

    while (!WindowShouldClose())
    {
        UpdatePlayerBlueChoice(rpsP2, graphics, playerBluePos, currentPhase);
        if (currentPhase == RpsPhase::PlayerRedAI)
        {
            UpdatePlayerRedAI(rpsP1, playerRedPos, currentPhase);
        }
        if (currentPhase == RpsPhase::TurnRpsIntoOne)
        {
            UpdateTurnPlayerRedIntoBack(playerRedPos, currentPhase);
        }
        if (currentPhase == RpsPhase::MovePlayerRed)
        {
            UpdatePlayerRedMovement(playerRedPos, currentPhase, rpsP1);
        }
        if (currentPhase == RpsPhase::RevealPlayerRed)
        {
            UpdateRevealPlayerRed(currentPhase);
        }

        if (currentPhase == RpsPhase::ShowResult)
        {
            isDraw = ((rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Rock) || (rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Paper) || (rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Scissor));
            redWins = ((rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Rock) || (rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Scissor) || (rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Paper));
            blueWins = ((rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Paper) || (rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Rock) || (rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Scissor));
            
            // Ergebnis dieser Runde nur EINMAL zählen
            if (!resultCounted)
            {
                if (redWins)
                {
                    redWinCount++;
                    TraceLog(LOG_INFO, "Red Wins: %d", redWinCount);
                }
                else if (blueWins)
                {
                    blueWinCount++;
                    TraceLog(LOG_INFO, "Blue Wins: %d", blueWinCount);
                }
                else if (isDraw)
                {
                    TraceLog(LOG_INFO, "Round is Draw");
                }

                resultCounted = true;
            }

            // Für ALLE Ergebnisse 1 Sekunde warten
            resultTimer += GetFrameTime();

            if (resultTimer >= 1.0f)
            {
                resultTimer = 0.0f;
                resultCounted = false;

                ResetRound(playerBluePos, playerRedPos, currentPhase);
            }
        }
        BeginDrawing();

        ClearBackground(DARKBLUE);
        DrawPlayground(graphics);

        DrawCount(graphics, redWinCount, blueWinCount);

        DrawGraphicsPlayerBlue(graphics, playerBluePos);
        DrawGraphicsPlayerRed(graphics, playerRedPos, currentPhase, rpsP1);
        if(isDraw && currentPhase == RpsPhase::ShowResult){
            DrawTextureEx(graphics.draw,{170.0f,240.0f},0.0f,4.0f,WHITE);
            DrawTextureEx(graphics.draw,{570.0f,240.0f},0.0f,4.0f,WHITE);
        }else if(redWins && currentPhase == RpsPhase::ShowResult){
            DrawTextureEx(graphics.arrow,{130.0f,130.0f},0.0f,4.0f,WHITE);
        }else if(blueWins && currentPhase == RpsPhase::ShowResult){
            DrawTextureEx(graphics.arrow,{130.0f,360.0f},0.0f,4.0f,WHITE);
        }
        if (currentPhase == RpsPhase::ShowResult)
        {
            //CheckResult(rpsP1, rpsP2);
        }
        EndDrawing();
    }
    UnloadGraphics(graphics);

    CloseWindow();

    return 0;
}