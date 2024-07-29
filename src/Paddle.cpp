#include "Paddle.hpp"

void Paddle::draw()
{
    DrawRectangleRec({x,y,width,height},WHITE);
}

void Paddle::update()
{
    if(IsKeyDown(KEY_LEFT))
    {
        x -= speed;
        //check if the paddle collides with the left side of the screen
        if(x <= 0.0f)
            x = 0.0f;
    }
    else if(IsKeyDown(KEY_RIGHT))
    {
        x += speed;
        //the same for the right side
        if(x+width >= float(GetScreenWidth()))
            x = float(GetScreenWidth()) - width ;
    }
}
