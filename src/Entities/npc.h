#ifndef NPCS_H
#define NPCS_H

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"
#include "../Graphics/debug_utils.h"
#include "player.h"
#include "interaction.h"


enum NPCStates { walking, running, attacking, idle };

class NPC : public RigidBody
{
	sf::Clock Timer;
	PressButton button;
	NPCStates state = idle;
	bool flipped = false;

	void updateState();

public:
	Animation walk_anim;
	Animation idle_anim;

	float speed = 0.01;
	bool chatter = false;
	bool evil = false;

	void init();
	void chat(StaticBody body, sf::RenderWindow* window);
	void wander();
	void follow(StaticBody body);
	void draw(sf::RenderWindow* window);
};


#endif
