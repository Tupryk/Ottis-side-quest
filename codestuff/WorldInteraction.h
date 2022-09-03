#ifndef WORLDINTERACTION
#define WORLDINTERACTION

class Dialog
{
public:
	void init();
	void drawNPC(std::string dialog);
	void drawPlayer(std::string dialog, int PossibleAwnsers);
	int PlayerAwnser();
	
	int LetterIndex = 0;
	bool AwnserGiven = false;
	bool Finished = false;
private:
	int PlayerCursorPos = 0;
	bool KeyBuffer = false;
	
	sf::Texture TextBoxTexture;
	sf::Sprite TextBox;

	sf::Texture LeftFaceTexture;
	sf::Sprite LeftFace;
	sf::Texture RightFaceTexture;
	sf::Sprite RightFace;
	sf::SoundBuffer buffer;
	sf::Sound sound;

	sf::Clock SpellingTimer;

	sf::Font font;
	sf::Text text;
	sf::Text cursor;
};

const int InteractionFrames = 11;

class Interaction
{
public:
	void init();
	void draw(int PosX, int PosY);
	bool activated = false;
private:
	int FrameIndex = -1;

	sf::Clock AnimationTimer;
	sf::Texture InteractionTexture[InteractionFrames];
	sf::Sprite Interaction;
};

#endif