#include <cmath>
#include <SFML/Graphics.hpp>

#include "sprites.h"


void StaticImage::load(std::string ImageDrirectory, float w, float h, float x, float y)
{
	texture.loadFromFile(ImageDrirectory, sf::IntRect(x, y, w, h));
	sprite.setTexture(texture);
	width = w;
	height = h;
}

void StaticImage::setScale(float x, float y)
{
	scaleX = x;
	scaleY = y;
	sprite.setScale(scaleX, scaleY);
	width *= scaleX;
	height *= scaleY;
}

void StaticImage::flip()
{
	flipped = !flipped;
	scaleX *= -1;
	sprite.setScale(scaleX, scaleY);
}

void StaticImage::draw(float x, float y, sf::RenderWindow* window)
{
	float set_y = y - height*0.5;
	float set_x;
	if (flipped) set_x = x + width*0.5;
	else set_x = x - width*0.5;

	sprite.setTexture(texture);
	sprite.setPosition(std::round(set_x), std::round(set_y));
	window->draw(sprite);
}

void Animation::load(std::string ImageDrirectory, int frames, int fps, float w, float h, float x, float y)
{
	this->frames = frames;
	this->fps = fps;
	texture = new sf::Texture[frames];
	for (int i = 0; i < frames; i++) {
		texture[i].loadFromFile(ImageDrirectory, sf::IntRect(x+(w*i), y, w, h));
		sprite.setTexture(texture[i]);
	}
	width = w;
	height = h;
}

void Animation::setScale(float x, float y)
{
	scaleX = x;
	scaleY = y;
	sprite.setScale(scaleX, scaleY);
	width *= scaleX;
	height *= scaleY;
}

void Animation::flip()
{
	flipped = !flipped;
	scaleX *= -1;
	sprite.setScale(scaleX, scaleY);
}

void Animation::update()
{
	sf::Time lastUpdate = Timer.getElapsedTime();
	if (lastUpdate.asMilliseconds() >= (1000/fps)) {
		if (reversed)
		{
			frameIndex++;
			if (frameIndex >= frames)
				frameIndex = 0;
		}
		else
		{
			frameIndex--;
			if (frameIndex < 0)
				frameIndex = frames-1;
		}
		Timer.restart();
	}
	sprite.setTexture(texture[frameIndex]);
}

void Animation::draw(float x, float y, sf::RenderWindow* window)
{
	update();
	float set_y = y - height*0.5;
	float set_x;
	if (flipped) set_x = x + width*0.5;
	else set_x = x - width*0.5;

	sprite.setPosition(std::round(set_x), std::round(set_y));
	window->draw(sprite);
}
