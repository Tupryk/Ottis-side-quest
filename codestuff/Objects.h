#ifndef OBJECTS
#define OBJECTS

class Ball
{
public:
	Ball();
	void eject(float ForceX, float ForceY);
	void update(int PersonFrameIndex);
	void draw();
	
	float Pos[2];
	float Vel[2];

	bool Grabbed = true;
private:
	float Friction = 0.1;
	const float BallGravity = -0.5;

	float accx = 0;
	float accy = 0;
	
	sf::Texture BallTexture;
	sf::Sprite Ball;

	sf::Clock Updater;
};

#endif