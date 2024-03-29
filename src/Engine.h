//
// Created by SwagDeNoli on 9/20/2019.
//

#ifndef ENGINE_H
#define ENGINE_H

#include "raylib.h"

class Engine
{
public:
    void Init();

    void UpdateGame(float deltaTime);

    void DrawGame();

    void CloseGame();

    void CaptureInput();

    void DrawRect(Rectangle rect, Color color);

    void DrawDebugRect(Rectangle rect);

    void DrawText(std::string text, Vector2 position, int size, Color color);

private:
    Vector2 RectCenter(Rectangle rectangle)
    {
        return Vector2{rectangle.width / 2.0f, rectangle.height / 2.0f};
    }

    Rectangle GetRectCenter(Rectangle rectToCenter)
    {
        Rectangle centeredRect = {rectToCenter.x - rectToCenter.width / 2, rectToCenter.y - rectToCenter.height / 2,
                                  rectToCenter.width, rectToCenter.height};
        return centeredRect;
    }

    void CheckCollisions();

};


#endif //PONG_ENGINE_H
