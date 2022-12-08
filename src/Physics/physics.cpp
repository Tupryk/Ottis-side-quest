#include "physics.h"


bool StaticBody::overLap(StaticBody2D Static)
{
	return (position.x + (size.x*0.5) >= Static.position.x - (Static.size.x*0.5)
			&& position.x - (size.x*0.5) <= Static.position.x + (Static.size.x*0.5)
			&& position.y + (size.y*0.5) >= Static.position.y - (Static.size.y*0.5)
			&& position.y - (size.y*0.5) <= Static.position.y + (Static.size.y*0.5));
}

bool StaticBody::overLapOffset(StaticBody2D Static, float x, float y, float w, float h)
{
	return (position.x + (size.x*0.5) + w >= Static.position.x - (Static.size.x*0.5)
			&& position.x - (size.x*0.5) - x <= Static.position.x + (Static.size.x*0.5)
			&& position.y + (size.y*0.5) + h >= Static.position.y - (Static.size.y*0.5)
			&& position.y - (size.y*0.5) - y <= Static.position.y + (Static.size.y*0.5));
}

void RigidBody::update(std::vector<StaticBody> bodies)
{
	// Update velocity
	{
		vec3d tmp;

		tmp.x      = velocity.x + acceleration.x;
		velocity.x = tmp.x - tmp.x*Friction;

		tmp.y      = velocity.y + acceleration.y - Gravity;
		velocity.y = tmp.y - tmp.y*AirResistance;
	}

	// Apply velocity to position
	position.x = position.x + velocity.x + ( 0.5 * acceleration.x );
	// Check for collisions
	for (auto body : bodies) {
		if (OverLap(body)) { // revert to old position
			position.x = position.x - (velocity.x + ( 0.5 * acceleration.x ));
			velocity.x = 0;
			break;
		}
	}

	// Repeat for y-axis
	position.y = position.y + velocity.y + ( 0.5 * acceleration.y ) - ( 0.5 * Gravity );
	for (auto body : bodies) {
		if (OverLap(body)) {
			position.y = position.y - (velocity.y + ( 0.5 * acceleration.y ) - ( 0.5 * Gravity ));
			velocity.y = -velocity.y * Bounciness;
			OnFloor = true;
			return;
		}
	}
	OnFloor = false;
}
