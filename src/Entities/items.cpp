#include "Entities/items.h"


Item::Item(std::string image_file, float w, float h, float x, float y)
{
	image.load(image_file, w, h, x, y);
	position.x = x;
	position.y = y;
	size.x = w;
	size.y = h;

	Gravity = -0.5;
	Friction = 0.05;
	AirResistance = 0.0001;
	Bounciness = 0.5;
}

void Item::getPicket(Character* player)
{
	if (picket) {
		if (!buttonBuffer && sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
			picket = false;
			buttonBuffer = true;
		} else {
			vec3d holding_pos = player->getHoldingPos();
			position.x = holding_pos.x;
			position.y = holding_pos.y;
			position.z = holding_pos.z;

			velocity.x = player->velocity.x;
			velocity.y = player->velocity.y;
			velocity.z = player->velocity.z;
		}
	}
	else {
		if (overLap(player) && !buttonBuffer && sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
			picket = true;
			buttonBuffer = true;
		}
	}
	if (buttonBuffer && !sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		buttonBuffer = false;
}

void Item::draw(sf::RenderWindow* window)
{
	image.draw(position.x, position.y, window);	
}
