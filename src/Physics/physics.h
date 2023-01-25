#ifndef PHYSICS
#define PHYSICS

#define STANDARD_GRAVITY -0.5

#include <vector>


struct vec2d
{
	float x = 0, y = 0;
};

struct vec3d
{
	float x = 0, y = 0, z = 0;
};

struct Segment2D
{
	vec2d start;
	vec2d end;
};

struct Segment3D
{
	vec3d start;
	vec3d end;
};

struct StaticBody
{
	vec3d position;
	vec3d size;

	bool overLap(StaticBody* body);
	bool overLapOffset(StaticBody* body, float x, float y, float w, float h);
	bool toTheRight(StaticBody* body);
};

struct RigidBody : StaticBody
{
	vec3d velocity;
	vec3d acceleration;

	float Gravity = 0;
	float Friction = 0;
	float AirResistance = 0;
	float Bounciness = 0;
	bool onFloor = false;

	virtual void update(std::vector<StaticBody> bodies = {}, float max_z = -1);
};

#endif