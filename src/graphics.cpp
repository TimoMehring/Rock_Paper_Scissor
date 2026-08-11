#include "graphics.h"

Graphics LoadGraphics(){
    Graphics graphics;
    graphics.rock = LoadTexture("assets/paper.png");

    return graphics;
}

void DrawGraphics(Graphics& graphics){
    
}