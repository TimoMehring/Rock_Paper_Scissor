#pragma once
#include "raylib.h"

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

enum class RpsPhase
{
    PlayerBlueChoice,
    MovePlayerBlue,
    PlayerRedAI,
    TurnRpsIntoOne,
    MovePlayerRed,
    RevealPlayerRed,
    ShowResult,

    PlayerRedWins,
    PlayerBlueWins,

    StartNewMatch

};

enum class Players{
    PlayerRed,
    PlayerBlue
};

struct PlayerBlueRpsPosition{
    Vector2 rockPosPlayerBlue{254.0f,476.0f};
    Vector2 paperPosPlayerBlue{398.0f, 476.0f};
    Vector2 scissorPosPlayerBlue{542.0f, 476.0f};
    bool rockSelected = false;
    bool paperSelected = false;
    bool scissorSelected = false;
};

struct PlayerRedRpsPosition{
    Vector2 rockPosPlayerRed{254.0f,20.0f};
    Vector2 paperPosPlayerRed{398.0f, 20.0f};
    Vector2 scissorPosPlayerRed{542.0f, 20.0f};
    Vector2 enemyPosPlayerRed{398.0f, 20.0f}; // After AI selected choice
    bool rockSelected = false;
    bool paperSelected = false;
    bool scissorSelected = false;
};