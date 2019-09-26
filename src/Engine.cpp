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

int playerScore = 0;
int aiScore = 0;

void Engine::Init()
{
    RAYLIB_H::InitWindow(screenSettings.width, screenSettings.height, screenSettings.screenTitle.c_str());

    RAYLIB_H::SetTargetFPS(screenSettings.targetFPS);

    player.rect = {50, GetScreenHeight() / 2.0f, 15, 120};
    player.color = WHITE;

}

void Engine::CaptureInput()
{
    if (IsKeyDown(KEY_UP))
    {
        if (player.IsInYScreenBounds())
        {
            player.rect.y -= player.speed.y * GetFrameTime();
        }
    }
    if (IsKeyDown(KEY_DOWN))
    {
        if (player.IsInYScreenBounds())
        {
            player.rect.y += player.speed.y * GetFrameTime();
        }
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
    RAYLIB_H::ClearBackground(screenSettings.backgroundColor);

    Engine::DrawRect(player.rect, player.color);

    Engine::DrawText(FormatText("Score: %d", playerScore), Vector2{0, 0}, 30, WHITE);

    Engine::DrawText(FormatText("Score: %d", aiScore), Vector2{GetScreenWidth() - 150.0f, 0}, 30.0f, WHITE);

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
    RAYLIB_H::DrawRectanglePro(rect, RectCenter(rect), 0, color);
}

void Engine::DrawDebugRect(Rectangle rect)
{
    RAYLIB_H::DrawRectangleLines(rect.x - (rect.width / 2), rect.y - (rect.height / 2), rect.width, rect.height,
                                 RED);
}

void Engine::DrawText(std::string text, Vector2 position, int size, Color color)
{
    RAYLIB_H::DrawText(text.c_str(), position.x, position.y, size, color);
}




