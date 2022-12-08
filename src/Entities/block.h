#ifndef BLOCK
#define BLOCK

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"


class Block : StaticBody
{
	StaticImage image;

public:
	Block(std::string ImageDrirectory, float x, float y, float w, float h);
	sf::Sprite draw();
};


#endif