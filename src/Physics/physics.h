#ifndef PHYSICS
#define PHYSICS

struct vec3d
{
	float x = 0, y = 0, z = 0;
};

struct StaticBody
{
	vec3d position;
	vec3d size;

	bool overLap(StaticBody2D Static);
	bool overLapOffset(StaticBody2D Static, float x, float y, float w, float h);
};

struct RigidBody : StaticBody
{
	vec3d velocity;
	vec3d acceleration;

	float Gravity = 0;
	float Friction = 0;
	float AirResistance = 0;
	bool OnFloor = false;
	float Bounciness = 0;

	void update(std::vector<StaticBody> bodies);
};

#endif