#include "character.h"


void Character::updateState()
{
	if (health <= 0)
		die();
	if (state != hurting) {
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
			hurt_anim.flip();
			flipped = !flipped;
		}
	} else {
		std::cout << "hurting" << std::endl;
		if (hurt_anim.frameIndex == hurt_anim.frames-1) {
			state = idle;
			hurt_anim.frameIndex = 0;
			updateState();
		}
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
	case hurting:
		hurt_anim.draw(relative_x, relative_y, window);
		break;
	default:
		idle_anim.draw(relative_x, relative_y, window);
		break;
	};
}

void Character::hurt(Character* character)
{
	if (character->state != hurting) {
		character->health -= damage;
		character->state = hurting;
	}
}

void Character::die()
{
	position.x = 0;
	position.y = 0;
	position.z = 0;
}

vec3d Character::getHoldingPos()
{
	vec3d pos = position;
	return pos;
}
