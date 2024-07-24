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
        if(x <= 0.0f) //check if the paddle collides with the left side of the screen
            x = 0.0f;
    }
    else if(IsKeyDown(KEY_RIGHT))
    {
        x += speed;
        if(x+80.0f >= float(GetScreenWidth())) //the same for the right side
            x = float(GetScreenWidth()) - 80.0f ;
    }
}
