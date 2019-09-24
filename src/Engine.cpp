//
// Created by SwagDeNoli on 9/20/2019.
//

#include "Engine.h"
#include "raylib.h"

struct Screen{
    int width;
    int height;
    int targetFPS;
};

Screen screenSettings = {800, 600, 60};

void Engine::Init()
{
    RAYLIB_H::InitWindow(screenSettings.width, screenSettings.height, "GameEngine");

    RAYLIB_H::SetTargetFPS(screenSettings.targetFPS);
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
