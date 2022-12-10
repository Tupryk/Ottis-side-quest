#ifndef CAMERA
#define CAMERA

#include "../Physics/physics.h"


class Camera : StaticBody
{
	int scene_w;
	int scene_h;

	int window_w;
	int window_h;

public:
	Camera(unsigned int window_w, unsigned int window_h, int scene_w = 0, int scene_h = 0);
	void draw(float x, float y, sf::RenderWindow* window);
};

class DynamicCamera : RigidBody
{
	int scene_w;
	int scene_h;

	int window_w;
	int window_h;

	float speed = 1;
	float offsetX = 0;
	float offsetY = 0;

public:
	DynamicCamera(unsigned int window_w, unsigned int window_h, int scene_w = 0, int scene_h = 0, float offsetX = 0, float offsetY = 0, float speed = 1);
	void draw(float x, float y, sf::RenderWindow* window);
};


#endif