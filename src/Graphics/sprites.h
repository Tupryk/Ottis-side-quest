#ifndef SPRITES
#define SPRITES

#include <SFML/Graphics.hpp>


class StaticImage
{
	sf::Texture texture;
	sf::Sprite sprite;
	float scaleX = 1;
	float scaleY = 1;
	float width, height;
	bool flipped = false;

public:
	void load(std::string ImageDrirectory, float x, float y, float w, float h);
	void setScale(float x, float y);
	void flip();
	sf::Sprite draw(float x, float y);
};

class Animation
{
	sf::Texture *texture;
	sf::Sprite sprite;
	sf::Clock Timer;
	float scaleX = 1;
	float scaleY = 1;
	float width, height; // for flipping the image

public:
	/* This parameters are set to public for
	   dynamically placing objects on an animation */
	int frames = 0;
	int frameIndex = 0;
	int fps = 1;
	bool flipped = false;
	bool reversed = false;

	void load(std::string ImageDrirectory, float x, float y, float w, float h, int frames, int fps);
	void setScale(float x, float y);
	void flip();
	void update();
	sf::Sprite draw(float x, float y);
};


#endif