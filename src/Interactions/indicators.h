#ifndef WORLD_INTERATION
#define WORLD_INTERATION

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"


struct ButtonIndicator
{
	int appearingFrame = 0;
	StaticBody* on_object = NULL;
};

class ButtonIndicators
{
	Animation appearing;
	Animation staying;
	std::vector<ButtonIndicator> on_objects;

	void draw_self(float x, float y, sf::RenderWindow* window, bool draw = true);

public:
	bool buffer = false;
	void init(char c = 'e');
	void add_object(StaticBody* body);
	void draw(float player_x, float player_y, sf::RenderWindow* window);
};


#endif
