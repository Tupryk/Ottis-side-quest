#include <cmath>
#include <SFML/Graphics.hpp>

#include "camera.h"


void DynamicCamera::init(unsigned int window_w, unsigned int window_h, int scene_w, int scene_h, float offsetX, float offsetY, float speed)
{
	this->scene_w = scene_w;
	this->scene_h = scene_h;
	this->window_w = window_w;
	this->window_h = window_h;
	this->offsetX = offsetX;
	this->offsetY = offsetY;
	this->speed = speed;

	Gravity = 0;
	Friction = 0.1;
	AirResistance = 0.1;
}

void DynamicCamera::draw(float x, float y, sf::RenderWindow* window)
{
	pop_up = false;
	
	if (position.x < x - offsetX)
		acceleration.x = speed;
	else if (position.x > x + offsetX)
		acceleration.x = -speed;
	else
		acceleration.x = 0;

	if (position.y < y - offsetY)
		acceleration.y = speed;
	else if (position.y > y + offsetY)
		acceleration.y = -speed;
	else
		acceleration.y = 0;

	update();

	if (position.x < 0)
		position.x = 0;
	if (position.y < 0)
		position.y = 0;

	if (position.x > scene_w)
		position.x = scene_w;
	if (position.y > scene_h)
		position.y = scene_h;

	sf::View camera(sf::FloatRect(std::round((-window_w*0.5) + position.x), std::round((-window_h*0.5) + position.y), window_w, window_h));
	window->setView(camera);
}

void Camera::init(unsigned int window_w, unsigned int window_h, int scene_w, int scene_h)
{
	this->scene_w = scene_w;
	this->scene_h = scene_h;
	this->window_w = window_w;
	this->window_h = window_h;
}

void Camera::draw(float x, float y, sf::RenderWindow* window)
{
	pop_up = false;

	position.x = x;
	position.y = y;

	if (position.x < 0)
		position.x = 0;
	if (position.y < 0)
		position.y = 0;

	if (position.x > scene_w)
		position.x = scene_w;
	if (position.y > scene_h)
		position.y = scene_h;

	sf::View camera(sf::FloatRect(std::round((-window_w*0.5) + position.x), std::round((-window_h*0.5) + position.y), window_w, window_h));
	window->setView(camera);
}


