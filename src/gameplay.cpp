#include "gameplay.h"
#include "raylib.h"

void CheckResult(RPSP1 rpsP1, RPSP2 rpsP2){
        if(rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Rock){
            DrawChoicePaperRock();
        }else if(rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Scissor){
            DrawChoiceRockScissor();
        }else if(rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Paper){
            DrawChoiceScissorPaper();
        }
        
        else if(rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Paper){ // Result = Draw
            DrawChoicePaperPaper();
        }else if(rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Rock){
            DrawChoiceRockRock();
        }else if(rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Scissor){
            DrawChoiceScissorScissor();
        }
        else if(rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Paper){ // Result = P1 
            DrawChoiceRockPaper();
        }else if(rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Rock){
            DrawChoiceScissorRock();
        }else if(rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Scissor){
            DrawChoicePaperScissor();
        }
}

void UpdatePlayerBlueChoice(RPSP2& rspP2,Graphics& graphics,PlayerBlueRpsPosition& playerBluePos){
    Rectangle rockRect = {254.0f,476.0f,graphics.rock.width *4.0f, graphics.rock.height *4.0f};

    Vector2 mousePosition = GetMousePosition();
// test for Rock only currently 
    if(CheckCollisionPointRec(mousePosition,rockRect)){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            rspP2 = RPSP2::Rock;
            playerBluePos.rockSelected = true;
        }
    }
    if(playerBluePos.rockSelected){
        Vector2 targetPosition = {398.0f, 300.0f};
        playerBluePos.rockPosPlayerBlue.y +=  (targetPosition.y - playerBluePos.rockPosPlayerBlue.y) * 0.05f;
    }
}