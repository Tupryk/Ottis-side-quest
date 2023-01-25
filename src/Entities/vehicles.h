#ifndef VEHICLES
#define VEHICLES

#include "../Physics/physics.h"
#include "../Graphics/sprite.h"


class Plane : RigidBody
{
	Animation flying_anim;
	vec3d direction; // controled by rotors
	float speed_for_takeoff;

public:
	void init();
	void update() override;
	void draw();
};


#endif
