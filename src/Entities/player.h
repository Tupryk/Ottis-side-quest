#ifndef PLAYER
#define PLAYER

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"


class Player : public RigidBody
{
	StaticImage image;

	float speed = 0.2;
	float jumpStrength = 7;
	bool jumpBuffer = false;

public:
	void init(std::string ImageDrirectory, float w, float h, float x = 0, float y = 0);
	void move();
	void draw(sf::RenderWindow* window);
};


#endif
