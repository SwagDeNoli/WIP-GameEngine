//
// Created by CHRIS on 9/20/2019.
//

#include "Engine.h"
#include "raylib.h"

Rectangle playerPaddle;
Rectangle aiPaddle;

Vector2 ballPosition;
Vector2 ballSpeed;
int ballRadius = 5;

bool debug = false;
Color ballColor = GREEN;

Vector2 RectCenter(Rectangle rectangle);

Rectangle CenteredRect(Rectangle rectToCenter);

void Engine::Init()
{
    RAYLIB_H::InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");

    SetTargetFPS(60);

    playerPaddle = {50, SCREEN_HEIGHT / 2.0f, 20, 125};
    aiPaddle = {SCREEN_WIDTH - 50.0f, SCREEN_HEIGHT / 2.0f, 20, 125};
    ballPosition = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
    ballSpeed = {-50, -50};


}

void Engine::UpdateGame(float deltaTime)
{
    //Get input
    if (IsKeyDown(KEY_UP))
    {
        playerPaddle.y -= GetFrameTime() * 100.0f;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        playerPaddle.y += GetFrameTime() * 100.0f;
    }
    if (IsKeyPressed(KEY_BACKSLASH))
    {
        debug = !debug;
    }
}

void Engine::DrawGame()
{

}

void Engine::CheckCollisions()
{

    ballPosition.x += ballSpeed.x * GetFrameTime() * 100;
}
