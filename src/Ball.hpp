#pragma once
#include <raylib.h>

class Ball
{

    public:

        Sound soundBall{LoadSound("sounds/ball_collision.wav")};
        float x,y,speedX{1.0f},speedY{1.0f},radius{4.0f};
        Color color{WHITE};

        void draw();
        void update();
};
