#include "player.h"


void Player::init(std::string ImageDrirectory, float w, float h, float x, float y)
{
	size.x = w;
	size.y = h;
	image.load(ImageDrirectory, w, h, x, y);

	Gravity = -0.5;
	Friction = 0.1;
	AirResistance = 0.01;
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			acceleration.x = speed * 2;
		else
			acceleration.x = speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			acceleration.x = -speed * 2;
		else
			acceleration.x = -speed;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		acceleration.x = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && onFloor && !jumpBuffer) {
		acceleration.y = -jumpStrength;
		jumpBuffer = true;
	} else if (onFloor && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		acceleration.y = 0;
		jumpBuffer = false;
	} else {
		acceleration.y = 0;
	}
}

void Player::draw(sf::RenderWindow* window)
{
	image.draw(position.x, position.y, window);
}
