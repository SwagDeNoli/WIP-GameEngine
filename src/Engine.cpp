//
// Created by SwagDeNoli on 9/20/2019.
//

#include <string>
#include "Engine.h"
#include "raylib.h"
#include "Player.h"

struct Screen
{
    int width;
    int height;
    int targetFPS;
    std::string screenTitle;
};

Screen screenSettings = {800, 600, 60, "Game Engine"};

Player player;

void Engine::Init()
{
    RAYLIB_H::InitWindow(screenSettings.width, screenSettings.height, screenSettings.screenTitle.c_str());

    RAYLIB_H::SetTargetFPS(screenSettings.targetFPS);

    player.rect = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, 50, 50};
    player.color = WHITE;
}

void Engine::CaptureInput()
{
    if (IsKeyDown(KEY_W))
    {
        player.rect.y -= player.speed.y;
    }
    if (IsKeyDown(KEY_S))
    {
        player.rect.y += player.speed.y;
    }
    if (IsKeyDown(KEY_A))
    {
        player.rect.x -= player.speed.x;
    }
    if (IsKeyDown(KEY_D))
    {
        player.rect.x += player.speed.x;
    }
}

void Engine::UpdateGame(float deltaTime)
{

}

void Engine::CheckCollisions()
{

}

//Draws every frame
void Engine::DrawGame()
{
    //BeginDraw, ClearBackground, EndDrawing must be in their respective lines, otherwise this will crash the program
    RAYLIB_H::BeginDrawing();
    RAYLIB_H::ClearBackground(BLACK);

    Engine::DrawRect(player.rect, player.color);

    RAYLIB_H::EndDrawing();
}

void Engine::CloseGame()
{
    CloseWindow();
}

void Engine::DrawRect(Rectangle rect, Color color)
{
    RAYLIB_H::DrawRectanglePro(rect, Vector2{rect.width/2, rect.height/2}, 0, color);
}


