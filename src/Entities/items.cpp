#include "items.h"


Item::Item(std::string image_file, float w, float h, float x, float y)
{
	image.load(image_file, w, h, x, y);
	position.x = x;
	position.y = y;
	size.x = w;
	size.y = h;

	Gravity = -0.5;
	Friction = 0.1;
	AirResistance = 0.01;
	Bounciness = 0.5;
}

void Item::draw(sf::RenderWindow* window)
{
	image.draw(position.x, position.y, window);	
}
