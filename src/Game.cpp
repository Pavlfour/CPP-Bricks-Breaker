#include "Game.hpp"

Game::Game()
{
    lastTime=0.0;
	for (int i{0},pickColor{GetRandomValue(0,19)},row{50};i<6;i++,row+=28) 
	{
        for(int j{0},column{45};j<13;j++,column+=55)
        {
            Brick brick;
            switch(pickColor%20)
            {
            case 0:
                brick.color = LIGHTGRAY;
                break;
            case 1:
                brick.color = GRAY;
                break;
            case 2:
                brick.color = YELLOW;
                break;
            case 3:
                brick.color = ORANGE;
                break;
            case 4:
                brick.color = PINK;
                break;
            case 5:
                brick.color = RED;
                break;
            case 6:
                brick.color = MAROON;
                break;
            case 7:
                brick.color = GREEN;
                break;
            case 8:
                brick.color = LIME;
                break;
            case 9:
                brick.color = DARKGREEN;
                break;
            case 10:
                brick.color = SKYBLUE;
                break;
            case 11:
                brick.color = BLUE;
                break;
            case 12:
                brick.color = DARKBLUE;
                break;
            case 13:
                brick.color = PURPLE;
                break;
            case 14:
                brick.color = VIOLET;
                break;
            case 15:
                brick.color = DARKPURPLE;
                break;
            case 16:
                brick.color = BEIGE;
                break;
            case 17:
                brick.color = BROWN;
                break;
            case 18:
                brick.color = DARKBROWN;
                break;
            case 19:
                brick.color = MAGENTA;
                break;
            }

            brick.x=(float)column;
            brick.y=(float)row;
            bricks.push_back(brick);
        }
        pickColor++;
    }

}

void Game::draw()
{
    //showing the score
    DrawText(TextFormat("Score %i",score),20,GetScreenHeight()-40,30,GREEN); 
    ball.draw();
    paddle.draw();
    //iteration to draw the bricks from the vector
    for(Brick brick:bricks)
        brick.draw();
}

void Game::update()
{

    if(!touchedBottom && !winner)
    {

        paddle.update();

        if(ballLaunched)
        {  
            ball.update();
            
            //check ball and paddle if they collide with each other
            if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{paddle.x,paddle.y,paddle.width,paddle.height}))
            {
                //added time to avoid the horizontal glitch between ball and paddle
                if(GetTime()-lastTime >=0.20) 
                {
                    PlaySound(soundBall);

                    //check which side of the paddle was collided with the ball
                    if((ball.x + ball.radius/2.0f < paddle.x) || (ball.x - ball.radius/2.0f > paddle.x+paddle.width))
                    {
                        ball.speedX *= -1.01f;
                        ball.speedY *= 1.01f;
                    }
                    else
                    {
                        //finding the x difference between ball and the paddle
                        diffX = ball.x - (paddle.x+paddle.width/2.0f);
                        //calculating the ball's overall speed
                        ballSpeed = sqrt(pow(ball.speedX,2.0)+pow(ball.speedY,2.0));

                        //scalar
                        diffX *= (PI/(paddle.width+20.0f));
                        //use all the above the determine the direction of the ball after collision with the paddle
                        ball.speedY = -1.01f * (ballSpeed * sin(PI/2.0f - diffX));
                        ball.speedX = 1.01f * (ballSpeed * cos(PI/2.0f - diffX));
                    }
                    PlaySound(soundBall);
                    lastTime = GetTime();
                }
            }

            //iteration to check collision between ball and the bricks
            for(Brick &brick: bricks)
            {
                if(brick.isAlive)
                {
                    //check collision
                    if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{brick.x,brick.y,brick.width+8.0f,brick.height+8.0f}))
                    {

                        PlaySound(soundBall);
                        //changing direction and speed of the ball
                        if((ball.x + ball.radius/2.0f < brick.x) || (ball.x - ball.radius/2.0f > brick.width+brick.x))
                        {
                            ball.speedX *= -1.01f;
                            ball.speedY *= 1.01f;
                        }
                        else 
                        {
                            ball.speedY *= -1.01f;
                            ball.speedX *= 1.01f;
                        }
                    //change the specific's live status to false
                    brick.isAlive = false;

                    score++;
                    if(score==78)
                    {
                        winner=true;
                        PlaySound(winnerSound);
                    }
                    break;
                    }
                }
            }

            //check collision between ball and the bottom of the screen
            if(ball.y-ball.radius >= float(GetScreenHeight()))
            {
                PlaySound(soundGameOver);
                touchedBottom=true;
            }
        }
        else
        {
            //we are at the launch state here
            ball.x = paddle.x+paddle.width/2.0f;
            ball.y = paddle.y-ball.radius;

            //get mouse coordinates
            mousePosition = GetMousePosition();
            diffX = (mousePosition.x - (paddle.x+paddle.width/2.0f));
            diffY = (mousePosition.y - (paddle.y-ball.radius));
            //using tangent to calculate the angle between mouse and ball
            angle = atan2(diffY,diffX);
            //draw launch line
            DrawLine(int(paddle.x+paddle.width/2.0f),
            int(paddle.y-ball.radius),
            int(paddle.x+paddle.width/2.0f+(170.0f)*cos(angle)), 
            int(paddle.y-ball.radius+(170.0f)*sin(angle)),
            WHITE);

            //launch the ball with Spacebar
            if(IsKeyDown(KEY_SPACE))
            {
                ballLaunched=true;
                //initial speed of the ball
                ball.speedX = (1.03f)*cos(angle);
                ball.speedY = (1.03f)*sin(angle);
                PlaySound(startLaunch);
            }
        }

    }
    else if(winner)
    {
        DrawText("Winner!!",GetScreenWidth()/2-winnerWidth/2+3,GetScreenHeight()/2,100,{ 119, 179, 0 ,200}); //outline
        DrawText("Winner!!",GetScreenWidth()/2-winnerWidth/2,GetScreenHeight()/2,100,{ 253, 249, 0, 255 }); //yellow
    }
    else
    {
        DrawText("Game Over",GetScreenWidth()/2-gameOverWidth/2+3,GetScreenHeight()/2,100,{ 119, 179, 0 , 200}); //outline
        DrawText("Game Over",GetScreenWidth()/2-gameOverWidth/2,GetScreenHeight()/2,100,{ 253, 249, 0, 255 }); //yellow
    }
}
