#include "Entities/objects.h"


void Object::draw(sf::RenderWindow* window) {
	image.draw(position.x, position.y + position.z, window);
}

void Puzzle::init(std::string image_path, float image_width, unsigned int dimensions)
{
	// Should readjust size depending on screen size
	this->dimensions = dimensions;
	this->cell_width = image_width/dimensions;

	{
		for (int i = 0; i < dimensions*dimensions; i++)
			positions.push_back(i-1);
		auto suffler = std::default_random_engine {};
		std::shuffle(std::begin(positions), std::end(positions), suffler);
	}

	for (int i = 1; i < dimensions*dimensions; i++) {
		StaticImage piece;
		piece.load(image_path, cell_width, cell_width,
			(i%dimensions)*cell_width, std::floor(i/dimensions)*cell_width);
		pieces.push_back(piece);
	}
}

void Puzzle::handle(Camera* camera, sf::RenderWindow* window)
{
	camera->pop_up = true;
	int empty_cell = find(positions.begin(), positions.end(), -1) - positions.begin();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
		&& (empty_cell/dimensions) != dimensions-1 && !button_buffer)
	{
		positions[empty_cell] = positions[empty_cell+dimensions];
		positions[empty_cell+dimensions] = -1;
		button_buffer = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
		&& (empty_cell%dimensions) != dimensions-1 && !button_buffer)
	{
		positions[empty_cell] = positions[empty_cell+1];
		positions[empty_cell+1] = -1;
		button_buffer = true;	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
		&& (empty_cell/dimensions) != 0 && !button_buffer)
	{
		positions[empty_cell] = positions[empty_cell-dimensions];
		positions[empty_cell-dimensions] = -1;
		button_buffer = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
		&& (empty_cell%dimensions) != 0 && !button_buffer) {
		positions[empty_cell] = positions[empty_cell-1];
		positions[empty_cell-1] = -1;
		button_buffer = true;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 
		!sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		button_buffer = false;

	// Draw pieces
	for (int i = 0; i < dimensions*dimensions; i++)
	{
		if (positions[i] >= 0)
			pieces[positions[i]].draw(
				std::round((i%dimensions)*cell_width),
				std::round(std::floor(i/dimensions)*cell_width), window);
	}
}

bool Puzzle::solved()
{
	for (int i = 0; i < positions.size(); i++) {
		if (positions[i] != i-1) return false; }
	return true;
}
