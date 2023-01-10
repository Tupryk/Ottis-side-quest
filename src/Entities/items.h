#ifndef ITEMS
#define ITEMS

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"
#include "../Entities/character.h"


class Item : public RigidBody
{
	StaticImage image;
	bool picket = false;
	bool buttonBuffer = false;

public:
	Item(std::string image_file, float w, float h, float x = 0, float y = 0);
	void getPicket(Character* player);
	void draw(sf::RenderWindow* window);
};


#endif
