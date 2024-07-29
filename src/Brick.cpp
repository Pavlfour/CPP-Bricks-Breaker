#include "Brick.hpp"

void Brick::draw()
{
    if(isAlive)
    {
        DrawRectangleRounded(Rectangle{x,y,width+8.0f,height+8.0f},0.2f,4,color);
        DrawRectangleRoundedLines(Rectangle{x,y,width+8.0f,height+8.0f},0.2f,4,2.0f,Color{color.r,color.g,color.b,100});
    }
}
