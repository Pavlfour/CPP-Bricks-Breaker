#pragma once
#include <vector>
#include <cmath>
using namespace std;
#include "Brick.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"


class Game
{
    public:

        //methods
        Game();
        void update();
        void draw();

    
        //attributes
        Sound soundGameOver{LoadSound("sounds/game_over.wav")};
        Sound startLaunch{LoadSound("sounds/start.wav")};
        Sound winnerSound{LoadSound("sounds/win.wav")};
        Sound soundBall{LoadSound("sounds/ball_collision.wav")};
        vector<Brick>bricks;
        Paddle paddle;
        Ball ball;
        Vector2 mousePosition;
        bool winner{false};
        double lastTime;
        bool touchedBottom{false};
        int gameOverWidth{MeasureText("Game Over",100)};
        int winnerWidth{MeasureText("Winner!!",100)};
        int score{0};
        bool ballLaunched{false};
        
};