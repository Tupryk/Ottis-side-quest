#ifndef OBJECTS
#define OBJECTS

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"
#include "../Entities/character.h"


struct Object : StaticBody
{
	StaticImage image;
};

class Chair : Object
{
public:
	void sit(Character* character);
};

class Puzzle : Object
{
	unsigned int dimensions = 3;
};


#endif
