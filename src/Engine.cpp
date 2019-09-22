//
// Created by SwagDeNoli on 9/20/2019.
//

#include "Engine.h"
#include "raylib.h"

void Engine::Init()
{
    RAYLIB_H::InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");

    SetTargetFPS(60);
}

void Engine::CaptureInput()
{

}

void Engine::UpdateGame(float deltaTime)
{

}

//Draws every frame
void Engine::DrawGame()
{
    //BeginDraw, ClearBackground, EndDrawing must be in their respective lines, otherwise this will crash the program
    BeginDrawing();
    ClearBackground(BLACK);


    EndDrawing();
}


void Engine::CheckCollisions()
{

}


void Engine::CloseGame()
{
    CloseWindow();
}
