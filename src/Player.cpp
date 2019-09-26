//
// Created by CHRIS on 9/24/2019.
//

#include "Player.h"

bool Player::IsInXScreenBounds(){
    int screenWidth = GetScreenWidth();

    //Check to see if rect is past screen border on X/Y axis
    if (rect.x + (rect.width / 2) >= screenWidth || rect.x - (rect.width / 2) <= 0)
    {
        return false;
    }

    //Rect isn't past border, return true
    return true;
}

bool Player::IsInYScreenBounds()
{
    int screenHeight = GetScreenHeight();

    if (rect.y + (rect.height / 2) >= screenHeight || rect.y - (rect.height / 2) <= 0)
    {
        return false;
    }
    return true;
}
