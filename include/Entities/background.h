#pragma once

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"
#include "../Graphics/camera.h"


class Slice : StaticBody
{
	StaticImage image;

public:
	void init(float pos_x, float pos_y, float pos_z, std::string ImageDrirectory, float w, float h, float x = 0, float y = 0);
	void draw(Camera camera, sf::RenderWindow* window);
};
