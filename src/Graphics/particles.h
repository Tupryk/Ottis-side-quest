#ifndef PARTICLES
#define PARTICLES

#include <cmath>
#include <SFML/Graphics.hpp>

#include "../Physics/physics.h"


struct Particle : RigidBody
{
	int r, g, b;
public:
	Particle(float r, float g, float b);
};

class Particles : StaticBody
{
	std::vector<Particle> bodies;

	unsigned int count;

	vec3d max_acc;
	vec3d min_acc;

	float max_r;
	float min_r;
	float max_g;
	float min_g;
	float max_b;
	float min_b;

	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	void generate();

public:
	bool respawn = true;

	void init(unsigned int min_r, unsigned int min_g, unsigned int min_b,
			  unsigned int max_r, unsigned int max_g, unsigned int max_b,
			  unsigned int count, float min_acc_x, float min_acc_y, float max_acc_x, float max_acc_y,
			  float size_x = 10000, float size_y = 10000, float Gravity = STANDARD_GRAVITY);
	void blow(float acc_x, float acc_y);
	void update();
	void update(float x, float y);
	void draw(sf::RenderWindow* window);
};


#endif
