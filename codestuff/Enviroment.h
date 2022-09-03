#ifndef ENVIROMENT
#define ENVIROMENT

class Backround
{
public:
	void init();
	void draw();
private:
	int FrameIndex = 0;
	bool GoingUp = false;

	sf::Texture Layer0Texture[3];
	sf::Texture Layer1Texture[3];
	sf::Texture Layer2Texture[3];
	sf::Texture Layer3Texture[3];
	sf::Sprite Layer[4];

	sf::Clock AnimationTimer;
};

class BackroundImg
{
public:
	void init();
	void draw();

private:
	sf::Texture BackroundImg;
	sf::Sprite Backround;
	sf::Texture FaroTex;
	sf::Sprite Faro;
};

class Clouds
{
public:
	void init();
	void draw();
	void update();
private:
	float PosX[CloudsAmount];
	float PosY[CloudsAmount];
	float Vel[CloudsAmount];

	sf::Texture CloudTexture[CloudsAmount];
	sf::Sprite Cloud[CloudsAmount];
	sf::Clock CloudUpdater;
};

class Boat
{
public:
	void init();
	void draw();
private:
	const float Speed = 1;
	float PosX = (-ScreenWidth*0.5)-16;
	sf::Texture BoatTexture;
	sf::Sprite Boat;
	sf::Clock MovementTimer;
};

class Plataform
{
public:
	void init();
	void drawBack();
	void drawFront();
private:
	sf::Texture Piece1Texture;
	sf::Sprite Piece1;
	sf::Texture Piece2Texture;
	sf::Sprite Piece2;
};

#endif