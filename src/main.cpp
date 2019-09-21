#include <iostream>
#include "raylib.h"
#include "Engine.h"








void CheckCollisions();

int main()
{
    Engine engine;
    engine.Init();

    while (!WindowShouldClose())
    {
        engine.UpdateGame(GetFrameTime());
        engine.CheckCollisions();
        engine.DrawGame();
    }
    CloseWindow();
    return 0;
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



