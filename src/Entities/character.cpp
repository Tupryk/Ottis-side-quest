#include "character.h"


void Character::updateState()
{
	if (state == sitting) return; // Sitting state needs to be switched from the outside

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

	if (health <= 0) die();
	if (state == damaged && !hurt_anim.finished) return;
	if (state == attacking && !attack_anim.finished) return;
	hurt_anim.reset();
	attack_anim.reset();

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
	case damaged:
		hurt_anim.draw(relative_x, relative_y, window);
		break;
	default:
		idle_anim.draw(relative_x, relative_y, window);
		break;
	};
}

void Character::hurt(Character* character)
{
	// needs a cooldown for taking damage
	if (character->state != damaged) {
		character->health -= damage;
		character->state = damaged;
		if (toTheRight(character))
			character->velocity.x = -knockback;
		else
			character->velocity.x = knockback;
	}
}

void Character::die()
{
	position.x = 0;
	position.y = 0;
	position.z = 0;

	velocity.x = 0;
	velocity.y = 0;
	velocity.z = 0;

	acceleration.x = 0;
	acceleration.y = 0;
	acceleration.z = 0;

	health = max_health;
}

vec3d Character::getHoldingPos()
{
	vec3d pos = position;
	return pos;
}
