#include "physics.h"


bool StaticBody::overLap(StaticBody body)
{
	return (position.x + (size.x*0.5) >= body.position.x - (body.size.x*0.5)
			&& position.x - (size.x*0.5) <= body.position.x + (body.size.x*0.5)
			&& position.y + (size.y*0.5) >= body.position.y - (body.size.y*0.5)
			&& position.y - (size.y*0.5) <= body.position.y + (body.size.y*0.5));
}

bool StaticBody::overLapOffset(StaticBody body, float x, float y, float w, float h)
{
	return (position.x + (size.x*0.5) + w >= body.position.x - (body.size.x*0.5)
			&& position.x - (size.x*0.5) - x <= body.position.x + (body.size.x*0.5)
			&& position.y + (size.y*0.5) + h >= body.position.y - (body.size.y*0.5)
			&& position.y - (size.y*0.5) - y <= body.position.y + (body.size.y*0.5));
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
		if (overLap(body)) { // revert to old position
			position.x = position.x - (velocity.x + ( 0.5 * acceleration.x ));
			velocity.x = 0;
			break;
		}
	}

	// Repeat for y-axis
	position.y = position.y + velocity.y + ( 0.5 * acceleration.y ) - ( 0.5 * Gravity );
	for (auto body : bodies) {
		if (overLap(body)) {
			position.y = position.y - (velocity.y + ( 0.5 * acceleration.y ) - ( 0.5 * Gravity ));
			velocity.y = -velocity.y * Bounciness;
			onFloor = true;
			return;
		}
	}
	onFloor = false;
}
