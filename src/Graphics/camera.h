#ifndef CAMERA
#define CAMERA

#include "../Physics/physics.h"


class Camera : StaticBody
{
	unsigned int screenWidth = 64;
	unsigned int screenHeight = 32;
public:
	Camera(unsigned int screenWidth, unsigned int screenHeight);
	void draw(float x, float y);
};

class DynamicCamera : RigidBody
{
	unsigned int screenWidth = 64;
	unsigned int screenHeight = 32;

	float speed = 1;
	float offsetX = 0;
	float offsetY = 0;

public:
	DynamicCamera(unsigned int screenWidth, unsigned int screenHeight, float offsetX, float offsetY, float speed);
	void draw(float x, float y);
};


#endif