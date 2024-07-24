#include <raylib.h>
#include "Game.hpp"

int main()
{

    SetConfigFlags(FLAG_VSYNC_HINT); //synchronized game frame rate with screen frame rate

    InitWindow(805,800,"Bricks Breaker");
    InitAudioDevice();


    //positioning the window to the center of the monitor
    SetWindowPosition((int)(GetMonitorWidth(GetCurrentMonitor()) / 2) - (int)(805 / 2), (int)(GetMonitorHeight(GetCurrentMonitor()) / 2) - (int)(800 / 2));

    Game game;

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        //initializing
        game.update();
        game.draw();
        

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}