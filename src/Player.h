//
// Created by CHRIS on 9/24/2019.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player
{
public:
    RAYLIB_H::Rectangle rect;
    Color color;
    Vector2 speed = {5, 5};
};


#endif //G_PLAYER_H
