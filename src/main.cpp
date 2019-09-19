#include <iostream>
#include "raylib.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

Rectangle rect;

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
    rect = {50, SCREEN_HEIGHT / 2.0f, 20, 125};
    ballPosition = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
    ballSpeed = {50, 50};
}

void UpdateGame()
{
    //Get input
    if (IsKeyDown(KEY_UP))
    {
        rect.y -= GetFrameTime() * 100.0f;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        rect.y += GetFrameTime() * 100.0f;
    }
    if (IsKeyPressed(KEY_BACKSLASH))
    {
        debug = !debug;
    }

    //Collision Detection
    //Temp Rect, centered to drawn rect
    Rectangle collisionRect = CenteredRect(rect);
    bool collision = CheckCollisionCircleRec(ballPosition, ballRadius, collisionRect);

    if (collision)
    {
        ballPosition.y *= -1;
    }

    ballPosition.y += ballSpeed.y * GetFrameTime();
    ballPosition.x += ballSpeed.x * GetFrameTime();
}

void DrawGame()
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectanglePro(rect, RectCenter(rect), 0, WHITE);
    DrawCircleV(ballPosition, ballRadius, ballColor);
    if (debug)
    {
        //Draw debug lines as if rectangle is drawn from top-left corner
        DrawRectangleLinesEx(rect, 1.0f, RED);
        //Draw debug lines as if it has its center aligned
        DrawRectangleLines(rect.x - rect.width / 2, rect.y - rect.height / 2, rect.width, rect.height, BLUE);
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