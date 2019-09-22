#include <iostream>
#include "raylib.h"
#include "Engine.h"


int main()
{
    Engine engine;
    engine.Init();

    while (!WindowShouldClose())
    {
        engine.UpdateGame(GetFrameTime());
        engine.DrawGame();
    }

    engine.CloseGame();

    return 0;
}






