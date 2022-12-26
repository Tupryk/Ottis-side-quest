#ifndef ITEMS
#define ITEMS

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"


class Item : public RigidBody
{
	StaticImage image;

public:
	Item(std::string image_file, float w, float h, float x = 0, float y = 0);
	void draw(sf::RenderWindow* window);
};


#endif
