//
// Created by CHRIS on 9/22/2019.
//

#include "Paddle.h"

void Paddle::Init()
{
    rect = {50, 300, 20, 125};

}

void Paddle::Update(float dt)
{

}

void Paddle::Draw()
{
    DrawRectanglePro(rect, Vector2{rect.width / 2.0f, rect.height / 2.0f}, 0, color);
}
