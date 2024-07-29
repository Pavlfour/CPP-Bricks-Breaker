#pragma once
#include <raylib.h>

class Brick
{

    public:

        float x,y,width{40.0f},height{14.0f};
        bool isAlive{true};
        Color color;

        void draw();
};
