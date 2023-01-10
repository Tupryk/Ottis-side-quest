#include "player.h"


void Player::init()
{
	size.x = 16;
	size.y = 16;

	Gravity = -0.5;
	Friction = 0.1;
	AirResistance = 0.01;
	speed = 0.2;
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			acceleration.z = speed * 4;
		else
			acceleration.z = speed * 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			acceleration.z = -speed * 4;
		else
			acceleration.z = -speed * 2;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		acceleration.x = 0;
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		acceleration.z = 0;

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

vec3d Character::getHoldingPos()
{
	vec3d pos = position;
	return pos;
}
