#include "Ball.hpp"

void Ball::draw()
{
    DrawCircle(int(x),int(y),radius,color);
}

void Ball::update()
{
    x += speedX;
    y += speedY;
    
    //check borders
    if(x-radius <= 0.0f || x+radius >= float(GetScreenWidth()))
    {
        speedX *= -1.005;
        PlaySound(soundBall);
    }
    if(y-radius <= 0.0f)
    {
        speedY *= -1.005;
        PlaySound(soundBall);
    }
}
