#include "particles.h"


Particle::Particle(unsigned int r, unsigned int g, unsigned int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->size.x = 1;
	this->size.y = 1;
}

void Particle::place(float pos_x, float pos_y, float pos_z)
{
	position.x = pos_x;
	position.y = pos_y;
	position.z = pos_z;
}

void Particle::blow(float acc_x, float acc_y, float acc_z)
{
	velocity.x += acc_x;
	velocity.y += acc_y;
	velocity.z += acc_z;
}

void Particles::init(unsigned int count, Segment3D color_range, Segment3D acc_range, 
		  			 vec3d size, float gravity)
{
	this->count = count;
	this->acc_range = acc_range;
	this->color_range = color_range;
	this->size = size;
	this->gravity = gravity;

	sprite.setOrigin(size.x*0.5, size.y*0.5);

	generate();
}

Particle Particles::generate_unit()
{
	// Generate colors
	int r = rand()%(static_cast<int>(color_range.start.x-color_range.end.x) + 1) + color_range.end.x;
	int g = rand()%(static_cast<int>(color_range.start.y-color_range.end.y) + 1) + color_range.end.y;
	int b = rand()%(static_cast<int>(color_range.start.z-color_range.end.z) + 1) + color_range.end.z;
	Particle part(r, g, b);

	// Generate starting velocity
	{
		part.Gravity = gravity;
		int min = static_cast<int>(acc_range.start.x*1000);
		int max = static_cast<int>(acc_range.end.x*1000);
		part.velocity.x += static_cast<float>(rand()%(max-min + 1) + min)*0.001;
		min = static_cast<int>(acc_range.start.y*1000);
		max = static_cast<int>(acc_range.end.y*1000);
		part.velocity.y += static_cast<float>(rand()%(max-min + 1) + min)*0.001;
	}

	// Place particle in correct spot
	part.place(size.x, size.y);

	return part;
}

void Particles::generate()
{
	for (int i = 0; i < count; i++)
		bodies.push_back(generate_unit());
}

void Particles::blow(float acc_x, float acc_y, float acc_z)
{
	for (int i = 0; i < bodies.size(); i++) {
		bodies[i].blow(acc_x, acc_y, acc_z);
	}
}

void Particles::update(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	update();
}

void Particles::update()
{
	for (int i = 0; i < bodies.size(); i++) {
		bodies[i].update();
		if (!overLap(&bodies[i])) {
			if (respawn) bodies[i] = generate_unit();
			else bodies.erase(bodies.begin()+i);
		}
	}
}

void Particles::draw(sf::RenderWindow* window)
{
	image.create(size.x, size.y, sf::Color::White);
	image.createMaskFromColor(sf::Color::White, 0);
	for (int i = 0; i < bodies.size(); i++)
	{
		image.setPixel(std::round(bodies[i].position.x),
						std::round(bodies[i].position.y),
						sf::Color(bodies[i].r, bodies[i].g, bodies[i].b));
	}
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(std::round(position.x), std::round(position.y));
	window->draw(sprite);
}
