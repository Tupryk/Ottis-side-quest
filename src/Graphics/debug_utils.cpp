#include "debug_utils.h"


void drawPoint(float x, float y, sf::RenderWindow* window, float size)
{
	sf::CircleShape point(size);
	point.setFillColor(sf::Color(255, 0, 0));
	point.setPosition(x-(size*0.5), y-(size*0.5));
	window->draw(point);
}
