#ifndef BLOCK
#define BLOCK

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"


class Block : public StaticBody
{
	StaticImage image;

public:
	Block(std::string ImageDrirectory, float w, float h, float x = 0, float y = 0);
	void draw(sf::RenderWindow* window);
};


#endif