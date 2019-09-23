//
// Created by CHRIS on 9/22/2019.
//

#ifndef G_PADDLE_H
#define G_PADDLE_H

#include "raylib.h"

class Paddle
{
public:
    void Init();
    void Update(float dt);
    void Draw();

private:
    Rectangle rect;
    Color color = WHITE;
};


#endif //G_PADDLE_H
