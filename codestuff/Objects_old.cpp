#include "Objects.h"

void Ball::draw()
{
	Ball.setPosition(static_cast<int>(Pos[0]), static_cast<int>(Pos[1]));
	window.draw(Ball);
}

void Ball::update(int PersonFrameIndex)
{
	sf::Time lastGameUpdate = Updater.getElapsedTime(); //Ball needs to update before Dog!!!!
	if (lastGameUpdate.asMilliseconds() > 25)
	{
		float newPos[2];
		float newVel[2];

		newVel[1] = Vel[1] + accy + BallGravity*-1;
		Vel[1] = newVel[1];
		if (Vel[1] < 0.001){ Vel[1] = 0; }
		if (Pos[1] >= 138){ Vel[1] *= -0.5; Friction = 0.25; }
		else { Friction = 0.01; }
		newPos[1] = Pos[1]+Vel[1]+(0.5*accy)+(0.5*BallGravity*-1);
		
		newVel[0] = Vel[0] + accx;
		Vel[0] = newVel[0] - newVel[0]*Friction;
		newPos[0] = Pos[0]+Vel[0]+(0.5*accx);

		Pos[0] = newPos[0];
		Pos[1] = newPos[1];

		accx = 0;
		accy = 0;

		Updater.restart();
	}
	if (Grabbed)
	{
		switch(PersonFrameIndex)
		{
			case 0:
			Pos[0] = -100 + 19;
			Pos[1] = 98 + 22;
			break;
			case 1:
			Pos[0] = -100 + 3;
			Pos[1] = 98 + 14;
			break;
			case 2:
			Pos[0] = -100 + 10;
			Pos[1] = 98 + 1;
			break;
			case 3:
			Pos[0] = -100 + 38;
			Pos[1] = 98 + 3;
			eject(15+(rand()%7), -12-(rand()%6));
			break;
			
			case 6:
			Pos[0] = -100 + 36;
			Pos[1] = 98 + 37;
			break;
			case 7:
			Pos[0] = -100 + 29;
			Pos[1] = 98 + 26;
			break;
			case 8:
			Pos[0] = -100 + 19;
			Pos[1] = 98 + 19;
			break;
		}
		Vel[0] = 0;
		Vel[1] = 0;
	}
	//Don't go offscreen
	if (Pos[0] <= -ScreenWidth*0.5)
	{
		Pos[0] = -ScreenWidth*0.5;
	}
	if (Pos[0] >= LevelLength-ScreenWidth*0.5 - 10)
	{
		Pos[0] = LevelLength-ScreenWidth*0.5 - 10;
	}
	//Hit the floor
	if (Pos[1] >= 138){
		Pos[1] = 138;
    }
}

void Ball::init()
{
	BallTexture.loadFromFile(resourcePath() + "Assets/Img/Ball.png", sf::IntRect(0, 0, 2, 2));
	Ball.setTexture(BallTexture);
}

void Ball::eject(float ForceX, float ForceY)
{
	if(Grabbed)
    {
        accx = ForceX;
        accy = ForceY;
        Grabbed = false;
    }
}