#ifndef WORLD_INTERATION
#define WORLD_INTERATION

#include "../Graphics/sprites.h"


class PressButton
{
	Animation appearing;
	Animation staying;

public:
	void init(char c = 'e');
	void draw(float x, float y, sf::RenderWindow* window, bool draw);
};


#endif
