#include "npc.h"


void NPC::init(std::string ImageDrirectory, float w, float h, float x, float y)
{
	size.x = w;
	size.y = h;
	image.load(ImageDrirectory, w, h, x, y);

	Gravity = -0.5;
	Friction = 0.1;
	AirResistance = 0.01;
}

void NPC::wander()
{
	sf::Time lastUpdate = Timer.getElapsedTime();
	if (lastUpdate.asMilliseconds() >= 3000) {
		int go = rand()%3;
		if (go == 0) {
			acceleration.x = speed;
		} else if (go == 1) {
			acceleration.x = -speed;
		} else {
			acceleration.x = 0;
		}
		Timer.restart();
	}
}

void NPC::draw(sf::RenderWindow* window)
{
	image.draw(position.x, position.y, window);
}
