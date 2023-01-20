#ifndef CHARACTER
#define CHARACTER

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"


enum States { walking, running, jumping, falling, attacking, idle, damaged, sitting };

struct Character : public RigidBody
{
	Animation walk_anim;
	Animation idle_anim;
	Animation run_anim;
	Animation jump_anim;
	Animation fall_anim;
	Animation attack_anim;
	Animation hurt_anim;
	Animation sitting_anim;
	States state = idle;
	int health = 100;
	int max_health = 100;
	int damage = 10;
	float speed = 0.01;
	float knockback = 5;
	bool flipped = false;


	void die();
	void updateState();
	void draw(sf::RenderWindow* window);
	void hurt(Character* character);
	vec3d getHoldingPos();
};


#endif
