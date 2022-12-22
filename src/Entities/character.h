#ifndef CHARACTER
#define CHARACTER

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"


enum States { walking, running, jumping, falling, attacking, idle };

struct Character : public RigidBody
{
	Animation walk_anim;
	Animation idle_anim;
	Animation run_anim;
	Animation jump_anim;
	Animation fall_anim;
	Animation attack_anim;
	States state = idle;
	float speed = 0.01;
	int health = 100;
	bool flipped = false;

	void updateState();
	void draw(sf::RenderWindow* window);
};


#endif
