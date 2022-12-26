#include "block.h"


Block::Block(std::string ImageDrirectory, float w, float h, float x, float y)
{
	this->size.x = w;
	this->size.y = h;
	image.load(ImageDrirectory, w, h, x, y);
}

void Block::draw(sf::RenderWindow* window)
{
	image.draw(position.x, position.y, window);
}
