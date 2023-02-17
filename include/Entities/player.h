#pragma once

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"
#include "character.h"


class Player : public Character
{
	StaticImage image;

	float jumpStrength = 7;
	bool jumpBuffer = false;

public:
	void init();
	void move();
};
