#include "Particles.h"

void BloodParticles::init(Vertice2D position)
{
	for (int i = 0; i < ParticlesAmount; i++)
	{
		particles[i].acceleration.x = ((rand()%200)-100)*0.05;
		particles[i].acceleration.y = ((rand()%200)-100)*0.05;
		particles[i].ColorIntensity = (rand()%55)+200;
		particles[i].position.x = size.x*0.5;
		particles[i].position.y = size.y*0.5;
		particles[i].velocity.x = 0;
		particles[i].velocity.y = 0;
		particles[i].OnScreen = true;
	}
	size.x = 50;
	size.y = 50;
	Particles.setOrigin(size.x*0.5, size.y*0.5);
    Particles.setPosition(std::round(position.x), std::round(position.y));
}

void BloodParticles::draw()
{
	image.create(size.x, size.y, sf::Color::White);
	image.createMaskFromColor(sf::Color::White, 0);
	for (int i = 0; i < ParticlesAmount; i++)
	{
		if (particles[i].OnScreen)
		{
			image.setPixel(std::round(particles[i].position.x),
							std::round(particles[i].position.y),
							sf::Color(particles[i].ColorIntensity, 0, 0));
		}
	}
	texture.loadFromImage(image);
	Particles.setTexture(texture);
	window.draw(Particles);
}

void BloodParticles::update(Vertice2D position)
{
	bool someOnScreen = false;
	sf::Time lastUpdate = UpdateTimer.getElapsedTime();
	if (lastUpdate.asMilliseconds() > 50)
	{
		for (int i = 0; i < ParticlesAmount; i++)
		{
			if (particles[i].OnScreen)
			{
				particles[i].update_position();

				particles[i].acceleration.x = 0;
				particles[i].acceleration.y = 0;
			}
			if (particles[i].position.x >= size.x || particles[i].position.y >= size.y ||
				particles[i].position.x <= 0 || particles[i].position.y <= 0)
			{
				particles[i].OnScreen = false;
			} else {
				someOnScreen = true;
			}
		}
		UpdateTimer.restart();
	}
	if (someOnScreen)
	{
		draw();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
    	init(position);
    }
}
