#ifndef CHARACTER
#define CHARACTER

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"
#include "../Graphics/camera.h"
#include <iostream>


enum States { walking, running, jumping, falling, attacking, idle, hurting };

struct Character : public RigidBody
{
	Animation walk_anim;
	Animation idle_anim;
	Animation run_anim;
	Animation jump_anim;
	Animation fall_anim;
	Animation attack_anim;
	Animation hurt_anim;
	States state = idle;
	float speed = 0.01;
	int health = 100;
	int damage = 10;
	bool flipped = false;

	void die();
	void updateState();
	void draw(sf::RenderWindow* window);
	void hurt(Character* character);
	vec3d getHoldingPos();
};


#endif
