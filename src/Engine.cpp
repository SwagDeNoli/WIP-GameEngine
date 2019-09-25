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
    Color backgroundColor;
};

Screen screenSettings = {800, 600, 60, "Game Engine", BLACK};

Player player;

void Engine::Init()
{
    RAYLIB_H::InitWindow(screenSettings.width, screenSettings.height, screenSettings.screenTitle.c_str());

    RAYLIB_H::SetTargetFPS(screenSettings.targetFPS);

    player.rect = {50, GetScreenHeight() / 2.0f, 10, 120};
    player.color = WHITE;
}

void Engine::CaptureInput()
{
    if (IsKeyDown(KEY_W))
    {
        player.rect.y -= player.speed.y * GetFrameTime();
    }
    if (IsKeyDown(KEY_S))
    {
        player.rect.y += player.speed.y * GetFrameTime();
    }
    /*if (IsKeyDown(KEY_A))
    {
        player.rect.x -= player.speed.x * GetFrameTime();
    }
    if (IsKeyDown(KEY_D))
    {
        player.rect.x += player.speed.x * GetFrameTime();
    }*/
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
    RAYLIB_H::ClearBackground(screenSettings.backgroundColor);

    Engine::DrawRect(player.rect, player.color);

    Engine::DrawDebugRect(player.rect);

    RAYLIB_H::EndDrawing();
}

void Engine::CloseGame()
{
    CloseWindow();
}

//Wrapper function for drawing centered rectangles, with no rotation
void Engine::DrawRect(Rectangle rect, Color color)
{
    RAYLIB_H::DrawRectanglePro(rect, Vector2{rect.width/2, rect.height/2}, 0, color);
}

void Engine::DrawDebugRect(Rectangle rect)
{
    RAYLIB_H::DrawRectangleLines(rect.x - (rect.width / 2), rect.y - (rect.height / 2), rect.width, rect.height, RED);
}




