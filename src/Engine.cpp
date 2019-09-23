//
// Created by SwagDeNoli on 9/20/2019.
//

#include "Engine.h"
#include "raylib.h"
#include "Paddle.h"

Paddle playerPaddle;

void Engine::Init()
{
    RAYLIB_H::InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");

    SetTargetFPS(60);

    playerPaddle.Init();
}

void Engine::CaptureInput()
{

}

void Engine::UpdateGame(float deltaTime)
{
    playerPaddle.Update(deltaTime);
}

//Draws every frame
void Engine::DrawGame()
{
    //BeginDraw, ClearBackground, EndDrawing must be in their respective lines, otherwise this will crash the program
    BeginDrawing();
    ClearBackground(BLACK);

    playerPaddle.Draw();

    EndDrawing();
}


void Engine::CheckCollisions()
{

}


void Engine::CloseGame()
{
    CloseWindow();
}
