#include "gameplay.h"
#include "raylib.h"

void CheckResult(RPSP1 rpsP1, RPSP2 rpsP2){
        if(rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Rock){
            DrawChoicePaperRock();
        }else if(rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Scissor){
            // Draw DrawChoiceRockScissor
        }else if(rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Paper){
            //Draw DrawChoiceScissorPaper
        }
        
        else if(rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Paper){ // Result = Draw
            DrawChoicePaperPaper();
        }else if(rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Rock){
            //Draw Result = Draw
        }else if(rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Scissor){
            //Draw Result = Draw
        }
        else if(rpsP1 == RPSP1::Rock && rpsP2 == RPSP2::Paper){ // Result = P1 
            // Draw P1 Loose
        }else if(rpsP1 == RPSP1::Scissor && rpsP2 == RPSP2::Rock){
            // Draw P1 Loose
        }else if(rpsP1 == RPSP1::Paper && rpsP2 == RPSP2::Scissor){
            // Draw P1 Loose
        }
}