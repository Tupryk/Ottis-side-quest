#ifndef NPCS_H
#define NPCS_H

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"


class NPC : public RigidBody
{
	StaticImage image;
	sf::Clock Timer;
	float speed = 0.02;

public:
	void init(std::string ImageDrirectory, float w, float h, float x = 0, float y = 0);
	void wander();
	void draw(sf::RenderWindow* window);
};


#endif
