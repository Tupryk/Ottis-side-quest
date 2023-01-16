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
	void load(std::string ImageDrirectory, float w, float h, float x = 0, float y = 0);
	void setScale(float x, float y);
	void flip();
	void draw(float x, float y, sf::RenderWindow* window);
};

class Animation
{
	sf::Texture *texture;
	sf::Sprite sprite;
	sf::Clock Timer;
	float scaleX = 1;
	float scaleY = 1;
	float width, height; // for flipping the image
	
	void update(bool reversed);

public:
	/* This parameters are set to public for
	   dynamically placing objects on an animation */
	int frames = 0;
	int frameIndex = 0;
	int fps = 1;
	bool flipped = false;
	bool finished = false;

	void load(std::string ImageDrirectory, int frames, int fps, float w, float h, float x = 0, float y = 0);
	void setScale(float x, float y);
	void flip();
	void draw(float x, float y, sf::RenderWindow* window, bool reversed = false);
	void reset();
};


#endif