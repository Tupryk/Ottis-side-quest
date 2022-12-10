#ifndef PLAYER
#define PLAYER

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"


class Player : public RigidBody
{
	StaticImage image;

	float speed = 0.3;
	float jumpStrength = 7;
	bool jumpBuffer = false;

public:
	Player(std::string ImageDrirectory, float x, float y, float w, float h);
	void move();
	void draw(sf::RenderWindow* window);
};


#endif