#pragma once
#include <raylib.h>


class Paddle{

    public:
        void draw();
        void update();
        float x{float(GetScreenWidth()/2) + 40.0f},
        y{float(GetScreenHeight()) - 100.0f},
        speed{4.0f},width{80.0f},height{8.0f};
        
};