#ifndef NPCs
#define NPCs

const int PersonFrames = 9;

class Person
{
public:
	void init();
	void draw();
	
	int FrameIndex = 0;

	bool Waiting = false;
	bool ThrowingBall = true;
	bool PickingUpBall = false;
private:
	sf::Texture PersonTexture[PersonFrames];
	sf::Sprite Person;
	sf::Clock AnimationTimer;
};

const int SeagullFrames = 5;

class Seagull
{
public:
	void init();
	void draw();
private:
	int FrameIndex = 0;
	sf::Texture SeagullTexture[SeagullFrames];
	sf::Sprite Seagull;
	sf::Clock AnimationTimer;
};

const int CatFrames = 5;

class Cat
{
public:
	void init();
	void draw();
	int PosX = 557;
	int PosY = 90;
	Interaction interactionButton;
private:
	void chat();
	int FrameIndex = 0;
	Dialog dialog;
	sf::Texture CatTexture[CatFrames];
	sf::Sprite Cat;
	sf::Clock AnimationTimer;
};

#endif