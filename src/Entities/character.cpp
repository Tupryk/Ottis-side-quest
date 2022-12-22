#include "character.h"


void Character::updateState()
{
	if (velocity.y < 0)
		state = jumping;
	else if (velocity.y > 0)
		state = falling;
	else if (abs(acceleration.x) == speed)
		state = walking;
	else if (abs(acceleration.x) == speed*2)
		state = running;
	else
		state = idle;

	if ((velocity.x < 0 && !flipped) || (velocity.x > 0 && flipped)) {
		walk_anim.flip();
		idle_anim.flip();
		run_anim.flip();
		jump_anim.flip();
		fall_anim.flip();
		attack_anim.flip();
		flipped = !flipped;
	}
}

void Character::draw(sf::RenderWindow* window)
{
	updateState();
	switch (state)
	{
	case walking:
		walk_anim.draw(position.x, position.y, window);
		break;
	case running:
		run_anim.draw(position.x, position.y, window);
		break;
	case jumping:
		jump_anim.draw(position.x, position.y, window);
		break;
	case falling:
		fall_anim.draw(position.x, position.y, window);
		break;
	case attacking:
		attack_anim.draw(position.x, position.y, window);
		break;
	default:
		idle_anim.draw(position.x, position.y, window);
		break;
	};
}
