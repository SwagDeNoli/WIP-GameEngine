//
// Created by SwagDeNoli on 9/20/2019.
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
    CaptureInput();

    CheckCollisions();

    ballPosition.x += ballSpeed.x * GetFrameTime() * 5;
    ballPosition.y += ballSpeed.y * GetFrameTime() * 5;
}

void Engine::DrawGame()
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectanglePro(playerPaddle, RectCenter(playerPaddle), 0, WHITE);
    DrawRectanglePro(aiPaddle, RectCenter(playerPaddle), 0, WHITE);
    DrawCircleV(ballPosition, ballRadius, ballColor);

    if (debug)
    {
        //Draw debug lines as if rectangle is drawn from top-left corner
        DrawRectangleLinesEx(playerPaddle, 1.0f, RED);
        //Draw debug lines as if it has its center aligned
        DrawRectangleLines(playerPaddle.x - playerPaddle.width / 2, playerPaddle.y - playerPaddle.height / 2,
                           playerPaddle.width, playerPaddle.height, BLUE);
    }
    EndDrawing();
}

void Engine::CheckCollisions()
{
    //Collision Detection
    //Temp Rect, centered to drawn playerPaddle
    Rectangle collisionRect = CenteredRect(playerPaddle);
    bool collision = CheckCollisionCircleRec(ballPosition, ballRadius, collisionRect);

    if (collision)
    {
        ballSpeed.y *= -1;
    }

    if (ballPosition.x + ballRadius + 1 >= SCREEN_WIDTH or ballPosition.x - ballRadius - 1 <= 0)
    {
        ballSpeed.x *= -1.0f;
        //ballSpeed.y *= -1.0f;
    }
    if (ballPosition.y + ballRadius + 1 >= SCREEN_HEIGHT or ballPosition.y - ballRadius - 1 <= 0)
    {
        //ballSpeed.x *= -1.0f;
        ballSpeed.y *= -1.0f;
    }

}

void Engine::CaptureInput()
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

Vector2 Engine::RectCenter(Rectangle rectangle)
{
    return Vector2{rectangle.width / 2.0f, rectangle.height / 2.0f};
}

Rectangle Engine::CenteredRect(Rectangle rectToCenter)
{
    Rectangle centeredRect = {rectToCenter.x - rectToCenter.width / 2, rectToCenter.y - rectToCenter.height / 2,
                              rectToCenter.width, rectToCenter.height};
    return centeredRect;
}

void Engine::CloseGame()
{
    CloseWindow();
}
