#include "npc.h"


void NPC::init()
{
	size.x = 16;
	size.y = 16;

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

void NPC::updateState()
{
	if (abs(acceleration.x) > 0)
		state = walking;
	else
		state = idle;
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
	updateState();
	switch (state)
	{
	case walking:
		walk_anim.draw(position.x, position.y, window);
		break;
	default:
		idle_anim.draw(position.x, position.y, window);
		break;
	};
}
