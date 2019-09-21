//
// Created by SwagDeNoli on 9/20/2019.
//

#ifndef PONG_ENGINE_H
#define PONG_ENGINE_H

#include "raylib.h"

class Engine
{
public:
    void Init();
    void UpdateGame(float deltaTime);
    void DrawGame();

    Vector2 RectCenter(Rectangle rectangle);

    Rectangle CenteredRect(Rectangle rectToCenter);

private:
    int SCREEN_WIDTH = 800;
    int SCREEN_HEIGHT = 600;
    void CheckCollisions();
};


#endif //PONG_ENGINE_H
