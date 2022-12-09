#include <cmath>
#include <SFML/Graphics.hpp>

#include "camera.h"


DynamicCamera::DynamicCamera(unsigned int screenWidth, unsigned int screenHeight, float offsetX, float offsetY, float speed)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->offsetX = offsetX;
	this->offsetY = offsetY;
	this->speed = speed;

	Gravity = 0;
	Friction = 0.1;
	AirResistance = 0.1;
}

void DynamicCamera::draw(float x, float y)
{
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
	sf::View camera(sf::FloatRect(std::round((-screenWidth*0.5) + position.x), std::round((-screenHeight*0.5) + position.y), screenWidth, screenHeight));
	//window.setView(camera);
}

Camera::Camera(unsigned int screenWidth, unsigned int screenHeight)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
}

void Camera::draw(float x, float y)
{
	position.x = x;
	position.y = y;
	sf::View camera(sf::FloatRect(std::round((-screenWidth*0.5) + position.x), std::round((-screenHeight*0.5) + position.y), screenWidth, screenHeight));
	//window.setView(camera);
}


