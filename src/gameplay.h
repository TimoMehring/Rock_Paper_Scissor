#pragma once
#include "raylib.h"
#include "states.h"
#include "graphics.h"

void CheckResult(RPSP1 rsp1, RPSP2 rsp2);
void UpdatePlayerBlueChoice(RPSP2& rspP2,Graphics& graphics,PlayerBlueRpsPosition& playerBluePos,RpsPhase& currentPhase);
RPSP1 ChoosePlayerRedAI();
void UpdatePlayerRedAI(RPSP1& rpsp1, PlayerRedRpsPosition& playerRedPos, RpsPhase& currentPhase);
void UpdatePlayerRedMovement(PlayerRedRpsPosition& playerRedPos,RpsPhase& currentPhase,RPSP1 rpsP1);
void UpdateTurnPlayerRedIntoBack(PlayerRedRpsPosition& playerRedPos, RpsPhase& currentPhase);
void UpdateRevealPlayerRed(RpsPhase& currentPhase);
void ResetRound(PlayerBlueRpsPosition& playerBluePos,PlayerRedRpsPosition& playerRedPos,RpsPhase& currentPhase);
