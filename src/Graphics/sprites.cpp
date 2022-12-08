#include <cmath>
#include <SFML/Graphics.hpp>

#include "sprites.h"


void StaticImage::load(std::string ImageDrirectory, float x, float y, float w, float h)
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

sf::Sprite StaticImage::draw(float x, float y)
{
	float set_y = y - height*0.5;
	float set_x;
	if (flipped) set_x = x + width*0.5;
	else set_x = x - width*0.5;

	sprite.setPosition(std::round(set_x), std::round(set_y));
	return sprite;
}

void Animation::load(std::string ImageDrirectory, float x, float y, float w, float h, int frames, int fps)
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
	}
	sprite.setTexture(texture[frameIndex]);
	Timer.restart();
}

sf::Sprite Animation::draw(float x, float y)
{
	update();
	float set_y = y - height*0.5;
	float set_x;
	if (flipped) set_x = x + width*0.5;
	else set_x = x - width*0.5;

	sprite.setPosition(std::round(set_x), std::round(set_y));
	return sprite;
}
