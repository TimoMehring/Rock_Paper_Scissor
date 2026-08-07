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