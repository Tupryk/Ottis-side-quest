#ifndef PARTICLES
#define PARTICLES

#include <cmath>
#include <SFML/Graphics.hpp>

#include "../Physics/physics.h"


struct Particle : RigidBody
{
	unsigned int r, g, b;

	Particle(unsigned int r, unsigned int g, unsigned int b);
	void place(float pos_x, float pos_y, float pos_z = 0);
	void blow(float acc_x, float acc_y, float acc_z = 0);
};

class Particles : StaticBody
{
	unsigned int count;
	float gravity;

	std::vector<Particle> bodies;
	Segment3D acc_range;
	Segment3D color_range;

	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	Particle generate_unit();
	void generate();

public:
	bool respawn = true;

	void init(unsigned int count, Segment3D color_range, Segment3D acc_range,
			  vec3d size, float gravity = STANDARD_GRAVITY);
	void blow(float acc_x, float acc_y, float acc_z = 0);
	void update();
	void update(float x, float y, float z = 0);
	void draw(sf::RenderWindow* window);
};


#endif
