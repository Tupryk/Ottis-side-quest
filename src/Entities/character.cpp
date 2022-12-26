#include "character.h"


void Character::updateState()
{
	if (velocity.y < 0)
		state = jumping;
	else if (velocity.y > 0)
		state = falling;
	else if (abs(acceleration.x) == speed || abs(acceleration.z) == (speed*2))
		state = walking;
	else if (abs(acceleration.x) == speed*2 || abs(acceleration.z) == (speed*4))
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
	float relative_x = position.x;
	float relative_y = position.y+position.z;
	updateState();
	switch (state)
	{
	case walking:
		walk_anim.draw(relative_x, relative_y, window);
		break;
	case running:
		run_anim.draw(relative_x, relative_y, window);
		break;
	case jumping:
		jump_anim.draw(relative_x, relative_y, window);
		break;
	case falling:
		fall_anim.draw(relative_x, relative_y, window);
		break;
	case attacking:
		attack_anim.draw(relative_x, relative_y, window);
		break;
	default:
		idle_anim.draw(relative_x, relative_y, window);
		break;
	};
}
