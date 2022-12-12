#include "npc.h"


void NPC::init(std::string ImageDrirectory, float w, float h, float x, float y)
{
	size.x = w;
	size.y = h;
	image.load(ImageDrirectory, w, h, x, y);

	Gravity = -0.5;
	Friction = 0.1;
	AirResistance = 0.01;

	button.init('e');
}
void NPC::chat(StaticBody body, sf::RenderWindow* window)
{
	button.draw(position.x, position.y-size.y, window, overLap(body));
}

void NPC::follow(StaticBody body)
{
	if (!overLap(body)) {
		if (body.position.x > position.x)
			acceleration.x = speed;
		else
			acceleration.x = -speed;
	} else {
		acceleration.x = 0;
	}
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
