#ifndef NPCS_H
#define NPCS_H

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"
#include "player.h"
#include "interaction.h"


class NPC : public RigidBody
{
	StaticImage image;
	sf::Clock Timer;
	PressButton button;

public:
	float speed = 0.02;
	bool chatter = false;
	bool evil = false;

	void init(std::string ImageDrirectory, float w, float h, float x = 0, float y = 0);
	void chat(StaticBody body, sf::RenderWindow* window);
	void wander();
	void follow(StaticBody body);
	void draw(sf::RenderWindow* window);
};


#endif
