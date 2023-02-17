#pragma once

#include <algorithm>
#include <random>

#include "../Physics/physics.h"
#include "../Graphics/sprites.h"
#include "../Graphics/camera.h"
#include "../Entities/character.h"
#include "../Interactions/indicators.h"


struct Object : StaticBody
{
	StaticImage image;
	void draw(sf::RenderWindow* window);
};

class Chair : Object
{
	bool occupied = false;

public:
	void sit(Character* character);
};

class Puzzle : Object
{
	unsigned int dimensions;
	unsigned int cell_width;
	bool button_buffer = false;

	std::vector<StaticImage> pieces; // If the dimensions are 3 there will be (3*3)-1 = 8 pieces.
	std::vector<int> positions; // There will be 3*3 = 9 possible positions.
	StaticImage background;

public:
	void init(std::string image_path, float image_width, unsigned int dimensions = 3); // Slices and shuffles image. (image must be square)
	void handle(Camera* camera, sf::RenderWindow* window); // Draws the puzzle up close and let's the player use it.
	bool solved();
};
