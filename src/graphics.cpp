#include "graphics.h"

Graphics LoadGraphics(){
    Graphics graphics;
    graphics.rock = LoadTexture("assets/rock.png");
    graphics.paper = LoadTexture("assets/paper.png");
    graphics.scissor = LoadTexture("assets/scissor.png");
    graphics.enemy = LoadTexture("assets/enemy.png");

    return graphics;
}

void DrawGraphics(Graphics& graphics, States currentState){
    if(currentState == States::Choice_Rock_Paper_Scissor){
        DrawPlayerRedGraphics(graphics);
        DrawPlayerBlueGraphics(graphics);
    }

}

void UnloadGraphics(Graphics& graphics){
    UnloadTexture(graphics.rock);
    UnloadTexture(graphics.paper);
    UnloadTexture(graphics.scissor);
    UnloadTexture(graphics.enemy);
}

void DrawPlayerRedGraphics(Graphics& graphics){
    DrawTextureEx(graphics.rock,{254.0f,20.0f},0.0f, 4.0f, WHITE);
    DrawTextureEx(graphics.paper,{398.0f, 20.0f},0.0f, 4.0f, WHITE);
    DrawTextureEx(graphics.scissor,{542.0f, 20.0f},0.0f, 4.0f, WHITE);
}

void DrawPlayerBlueGraphics(Graphics& graphics){
    DrawTextureEx(graphics.rock,{254.0f,476.0f},0.0f, 4.0f, WHITE);
    DrawTextureEx(graphics.paper,{398.0f, 476.0f},0.0f, 4.0f, WHITE);
    DrawTextureEx(graphics.scissor,{542.0f, 476.0f},0.0f, 4.0f, WHITE);
}
