#include <string>

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"
#include "block.h"


Block::Block(std::string ImageDrirectory, float x, float y, float w, float h)
{
	size.x = x;
	size.y = y;
	image.load(ImageDrirectory, x, y, w, h);
}

void Block::draw(sf::RenderWindow* window)
{
	image.draw(position.x, position.y, window);
}
