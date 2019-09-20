#include <iostream>
#include "raylib.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

Rectangle playerPaddle;
Rectangle aiPaddle;

Vector2 ballPosition;
Vector2 ballSpeed;
int ballRadius = 5;

bool debug = false;
Color ballColor = GREEN;

void InitGame();

void UpdateGame();

void DrawGame();

Vector2 RectCenter(Rectangle rectangle);

Rectangle CenteredRect(Rectangle rectToCenter);

void CheckCollisions();

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");

    InitGame();
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        UpdateGame();
        DrawGame();
    }
    CloseWindow();
    return 0;
}

void InitGame()
{
    playerPaddle = {50, SCREEN_HEIGHT / 2.0f, 20, 125};
    aiPaddle = {SCREEN_WIDTH - 50.0f, SCREEN_HEIGHT / 2.0f, 20, 125};
    ballPosition = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
    ballSpeed = {50, 50};
}

void UpdateGame()
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

    CheckCollisions();

    //Move Ball
    ballPosition.y += ballSpeed.y * GetFrameTime();
    ballPosition.x += ballSpeed.x * GetFrameTime();
}

void CheckCollisions()
{
    //Collision Detection
    //Temp Rect, centered to drawn playerPaddle
    Rectangle collisionRect = CenteredRect(playerPaddle);
    bool collision = CheckCollisionCircleRec(ballPosition, ballRadius, collisionRect);

    if (collision)
    {
        ballPosition.y *= -1;
    }


    if(ballPosition.x + ballRadius >= SCREEN_WIDTH){

    }
}

void DrawGame()
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectanglePro(playerPaddle, RectCenter(playerPaddle), 0, WHITE);
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

Vector2 RectCenter(Rectangle rectangle)
{
    return Vector2{rectangle.width / 2.0f, rectangle.height / 2.0f};
}

Rectangle CenteredRect(Rectangle rectToCenter)
{
    Rectangle centeredRect = {rectToCenter.x - rectToCenter.width / 2, rectToCenter.y - rectToCenter.height / 2,
                              rectToCenter.width, rectToCenter.height};
    return centeredRect;
}
