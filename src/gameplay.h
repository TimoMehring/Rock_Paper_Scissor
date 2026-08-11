#pragma once
#include "raylib.h"
#include "states.h"
#include "graphics.h"

enum class RPSP1{
    Rock,
    Paper,
    Scissor
};

enum class RPSP2{
    Rock,
    Paper,
    Scissor
};

void CheckResult(RPSP1 rsp1, RPSP2 rsp2);
void UpdatePlayerBlueChoice(RPSP2& rspP2,Graphics& graphics,PlayerBlueRpsPosition& playerBluePos);