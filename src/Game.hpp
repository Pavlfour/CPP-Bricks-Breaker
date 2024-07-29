#pragma once
#include <vector>
#include <cmath>
#include "Brick.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
using namespace std;

//this class works as the main control of the game
class Game
{

    public:
   
        Sound soundGameOver{LoadSound("sounds/game_over.wav")};
        Sound startLaunch{LoadSound("sounds/start.wav")};
        Sound winnerSound{LoadSound("sounds/win.wav")};
        Sound soundBall{LoadSound("sounds/ball_collision.wav")};
        vector<Brick>bricks;
        Paddle paddle;
        Ball ball;
        Vector2 mousePosition;
        double lastTime;
        bool touchedBottom{false},winner{false},ballLaunched{false};
        int winnerWidth{MeasureText("Winner!!",100)},gameOverWidth{MeasureText("Game Over",100)},score{0},lives{3};
        float diffX,diffY,angle,ballSpeed;

        Game();
        void update();
        void draw();
};
