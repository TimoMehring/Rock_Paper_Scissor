#pragma once
#include "raylib.h"

enum class Players{
    PlayerRed,
    PlayerBlue
};

struct PlayerBlueRpsPosition{
    Vector2 rockPosPlayerBlue{254.0f,476.0f};
    Vector2 paperkPosPlayerBlue{398.0f, 476.0f};
    Vector2 scissorPosPlayerBlue{542.0f, 476.0f};
    bool rockSelected = false;
};

struct PlayerRedRpsPosition{
    Vector2 rockPosPlayerRed{254.0f,20.0f};
    Vector2 paperkPosPlayerRed{398.0f, 20.0f};
    Vector2 scissorPosPlayerRed{542.0f, 20.0f};
};