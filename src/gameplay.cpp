#include "gameplay.h"
#include "raylib.h"
#include "player.h"

void CheckResult(RPSP1 rpsP1, RPSP2 rpsP2)
{
    if (rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Rock)
    {
        DrawChoicePaperRock();
    }
    else if (rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Scissor)
    {
        DrawChoiceRockScissor();
    }
    else if (rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Paper)
    {
        DrawChoiceScissorPaper();
    }

    else if (rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Paper)
    { // Result = Draw
        DrawChoicePaperPaper();
    }
    else if (rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Rock)
    {
        DrawChoiceRockRock();
    }
    else if (rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Scissor)
    {
        DrawChoiceScissorScissor();
    }
    else if (rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Paper)
    { // Result = P1
        DrawChoiceRockPaper();
    }
    else if (rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Rock)
    {
        DrawChoiceScissorRock();
    }
    else if (rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Scissor)
    {
        DrawChoicePaperScissor();
    }
}

void UpdatePlayerBlueChoice(RPSP2 &rspP2, Graphics &graphics, PlayerBlueRpsPosition &playerBluePos, RpsPhase &currentPhase)
{
    Rectangle rockRect = {254.0f, 476.0f, graphics.rock.width * 4.0f, graphics.rock.height * 4.0f};
    Rectangle paperRect = {398.0f, 476.0f, graphics.paper.width * 4.0f, graphics.paper.height * 4.0f};
    Rectangle scissorRect = {542.0f, 476.0f, graphics.scissor.width * 4.0f, graphics.scissor.height * 4.0f};

    Vector2 mousePosition = GetMousePosition();

    if (currentPhase == RpsPhase::PlayerBlueChoice)
    {
        if (CheckCollisionPointRec(mousePosition, rockRect))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                rspP2 = RPSP2::Rock;
                playerBluePos.rockSelected = true;
                playerBluePos.paperSelected = false;
                playerBluePos.scissorSelected = false;
                currentPhase = RpsPhase::MovePlayerBlue;
            }
        }
        if (CheckCollisionPointRec(mousePosition, paperRect))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                rspP2 = RPSP2::Paper;
                playerBluePos.rockSelected = false;
                playerBluePos.paperSelected = true;
                playerBluePos.scissorSelected = false;
                currentPhase = RpsPhase::MovePlayerBlue;
            }
        }
        if (CheckCollisionPointRec(mousePosition, scissorRect))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                rspP2 = RPSP2::Scissor;
                playerBluePos.rockSelected = false;
                playerBluePos.paperSelected = false;
                playerBluePos.scissorSelected = true;
                currentPhase = RpsPhase::MovePlayerBlue;
            }
        }
    }

    if (currentPhase == RpsPhase::MovePlayerBlue)
    {
        if (playerBluePos.rockSelected)
        {
            Vector2 targetPosition = {398.0f, 300.0f};
            playerBluePos.rockPosPlayerBlue.x += (targetPosition.x - playerBluePos.rockPosPlayerBlue.x) * 0.10f;
            playerBluePos.rockPosPlayerBlue.y += (targetPosition.y - playerBluePos.rockPosPlayerBlue.y) * 0.10f;
            if (playerBluePos.rockPosPlayerBlue.y <= 301.0f && playerBluePos.rockPosPlayerBlue.x >= 397.0f)
            {
                currentPhase = RpsPhase::PlayerRedAI;
            }
        }
        else if (playerBluePos.paperSelected)
        {
            Vector2 targetPosition = {398.0f, 300.0f};
            playerBluePos.paperPosPlayerBlue.y += (targetPosition.y - playerBluePos.paperPosPlayerBlue.y) * 0.10f;
            if (playerBluePos.paperPosPlayerBlue.y <= 301.0f)
            {
                currentPhase = RpsPhase::PlayerRedAI;
            }
        }
        else if (playerBluePos.scissorSelected)
        {
            Vector2 targetPosition = {398.0f, 300.0f};
            playerBluePos.scissorPosPlayerBlue.x += (targetPosition.x - playerBluePos.scissorPosPlayerBlue.x) * 0.10f;
            playerBluePos.scissorPosPlayerBlue.y += (targetPosition.y - playerBluePos.scissorPosPlayerBlue.y) * 0.10f;
            if (playerBluePos.scissorPosPlayerBlue.y <= 301.0f && playerBluePos.scissorPosPlayerBlue.x >= 397.0f)
            {
                currentPhase = RpsPhase::PlayerRedAI;
            }
        }
    }
}

RPSP1 ChoosePlayerRedAI()
{
    int randomChoice = GetRandomValue(0, 2);

    if (randomChoice == 0){
        return RPSP1::Rock;
    }
    else if (randomChoice == 1){
        return RPSP1::Paper;
    }
    else{
        return RPSP1::Scissor;
    }
}

void UpdatePlayerRedAI(RPSP1 &rpsP1, PlayerRedRpsPosition &playerRedPos, RpsPhase &currentPhase)
{
    rpsP1 = ChoosePlayerRedAI();

    if (rpsP1 == RPSP1::Rock){
        TraceLog(LOG_INFO, "PlayerRed AI chose: Rock");
        playerRedPos.rockSelected = true;
        playerRedPos.paperSelected = false;
        playerRedPos.scissorSelected = false;
    }
    else if (rpsP1 == RPSP1::Paper){
        TraceLog(LOG_INFO, "PlayerRed AI chose: Paper");
        playerRedPos.rockSelected = false;
        playerRedPos.paperSelected = true;
        playerRedPos.scissorSelected = false;
    }
    else if (rpsP1 == RPSP1::Scissor){
        TraceLog(LOG_INFO, "PlayerRed AI chose: Scissor");
        playerRedPos.rockSelected = false;
        playerRedPos.paperSelected = false;
        playerRedPos.scissorSelected = true;
    }
    
    currentPhase = RpsPhase::TurnRpsIntoOne;
}

void UpdateTurnPlayerRedIntoBack(PlayerRedRpsPosition& playerRedPos, RpsPhase& currentPhase){
    playerRedPos.rockPosPlayerRed.x += (398.0f - playerRedPos.rockPosPlayerRed.x) * 0.05f;
    playerRedPos.scissorPosPlayerRed.x += (398.0f - playerRedPos.scissorPosPlayerRed.x) * 0.05f;
    if(playerRedPos.rockPosPlayerRed.x >= 397.0f && playerRedPos.scissorPosPlayerRed.x <= 399.0f){
          TraceLog(LOG_INFO, "Phase changed to MovePlayerRed");
        currentPhase = RpsPhase::MovePlayerRed;
    }
}

void UpdatePlayerRedMovement(PlayerRedRpsPosition& playerRedPos,RpsPhase& currentPhase,RPSP1 rpsP1){
    Vector2 targetPosition = {398.0f, 150.0f};
    playerRedPos.enemyPosPlayerRed.y += (targetPosition.y - playerRedPos.enemyPosPlayerRed.y) * 0.10f;
    if(playerRedPos.enemyPosPlayerRed.y >= 149){
        currentPhase = RpsPhase::RevealPlayerRed;
    }
}

void UpdateRevealPlayerRed(RpsPhase& currentPhase){

        currentPhase = RpsPhase::ShowResult;
    
    
}

void ResetRound(PlayerBlueRpsPosition& playerBluePos,PlayerRedRpsPosition& playerRedPos,RpsPhase& currentPhase){
    // PlayerBlue start position
    playerBluePos.rockPosPlayerBlue = {254.0f, 476.0f};
    playerBluePos.paperPosPlayerBlue = {398.0f, 476.0f};
    playerBluePos.scissorPosPlayerBlue = {542.0f, 476.0f};

    playerBluePos.rockSelected = false;
    playerBluePos.paperSelected = false;
    playerBluePos.scissorSelected = false;

    // PlayerRed start position
    playerRedPos.rockPosPlayerRed = {254.0f, 20.0f};
    playerRedPos.paperPosPlayerRed = {398.0f, 20.0f};
    playerRedPos.scissorPosPlayerRed = {542.0f, 20.0f};

    playerRedPos.enemyPosPlayerRed = {398.0f, 20.0f};

    playerRedPos.rockSelected = false;
    playerRedPos.paperSelected = false;
    playerRedPos.scissorSelected = false;

    // new round
    currentPhase = RpsPhase::PlayerBlueChoice;
}