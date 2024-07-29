#include <raylib.h>
#include "Game.hpp"

int main()
{
    //synchronized game frame rate with screen frame rate
    SetConfigFlags(FLAG_VSYNC_HINT);

    InitWindow(805,800,"Bricks Breaker");
    InitAudioDevice();

    //positioning the window to the center of the monitor
    SetWindowPosition((int)(GetMonitorWidth(GetCurrentMonitor()) / 2) - (int)(805 / 2),
    (int)(GetMonitorHeight(GetCurrentMonitor()) / 2) - (int)(800 / 2));

    //initializing game object
    Game game;

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        game.update();
        game.draw();

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}
