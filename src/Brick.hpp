#pragma once
#include <raylib.h>

class Brick{
    public:

        //attributes
        float x{0.0f},y{0.0f},width{40.0f},height{14.0f};
        bool isAlive{true};
        Color color{WHITE};

        //methods
        void draw();
};
