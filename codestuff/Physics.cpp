//PHYSICS

const float Global_Gravity = -0.5;
const float Global_Friction = 0.1001;
const float Global_AirResistance = 0.01;

struct Vertice2D
{
	float x = 0;
	float y = 0;
};

struct StaticBody2D
{
	Vertice2D position;
	Vertice2D size;
	bool OverLap(StaticBody2D Static);
	bool OverLapOffset(StaticBody2D Static, float x, float y, float w, float h);
	void draw(){}
};

struct StaticBody2DList
{
	StaticBody2D* static_body;
	int Amount = 0;
	int count = 0;
	void init(int amount);
	void add_body(StaticBody2D NewStaticBody);
};

void StaticBody2DList::init(int amount)
{
	Amount = amount;
	static_body = new StaticBody2D[Amount];
}

void StaticBody2DList::add_body(StaticBody2D NewStaticBody)
{
	count++;
	static_body[count-1] = NewStaticBody;
}

//////////////////////////////////////// RIGIDBODY ///////////////////////////////////// VVVVVVV

struct RigidBody2D : StaticBody2D
{
	Vertice2D velocity;
	Vertice2D acceleration;
	Vertice2D NewVelocity;

	float Gravity = Global_Gravity;
	float Friction = Global_Friction;
	float AirResistance = Global_AirResistance;
	bool OnFloor = false;
	float Bounciness = 0;

	void update_vel();
	void apply_vel();
	void check_for_collisions_and_apply_acceleration(std::vector<StaticBody2D> static_bodies);
	void update_position(std::vector<StaticBody2D> static_bodies);
	void update_position();
};

void RigidBody2D::update_vel()
{
	NewVelocity.x = velocity.x + acceleration.x;
	velocity.x = NewVelocity.x - NewVelocity.x*Friction;

	NewVelocity.y = velocity.y + acceleration.y - Gravity;
	velocity.y = NewVelocity.y - NewVelocity.y*AirResistance;
}

void RigidBody2D::apply_vel()
{
	position.x = position.x + velocity.x + ( 0.5 * acceleration.x );
	position.y = position.y + velocity.y + ( 0.5 * acceleration.y ) - ( 0.5 * Gravity );
}

bool StaticBody2D::OverLap(StaticBody2D Static)
{
	return (position.x + (size.x*0.5) >= Static.position.x - (Static.size.x*0.5)
			&& position.x - (size.x*0.5) <= Static.position.x + (Static.size.x*0.5)
			&& position.y + (size.y*0.5) >= Static.position.y - (Static.size.y*0.5)
			&& position.y - (size.y*0.5) <= Static.position.y + (Static.size.y*0.5));
}

bool StaticBody2D::OverLapOffset(StaticBody2D Static, float x, float y, float w, float h)
{
	return (position.x + (size.x*0.5) + w >= Static.position.x - (Static.size.x*0.5)
			&& position.x - (size.x*0.5) - x <= Static.position.x + (Static.size.x*0.5)
			&& position.y + (size.y*0.5) + h >= Static.position.y - (Static.size.y*0.5)
			&& position.y - (size.y*0.5) - y <= Static.position.y + (Static.size.y*0.5));
}

void RigidBody2D::check_for_collisions_and_apply_acceleration(std::vector<StaticBody2D> static_bodies)
{
	bool Collision = false;

	//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
	position.x = position.x + velocity.x + ( 0.5 * acceleration.x );
	for (int i = 0; i < static_bodies.size(); i++)
	{
		if (OverLap(static_bodies[i]))
		{
			Collision = true;
		}
	}
	if (Collision)
	{
		position.x = position.x - (velocity.x + ( 0.5 * acceleration.x ));
		velocity.x = 0;
		Collision = false;
	}
	// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

	//YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
	position.y = position.y + velocity.y + ( 0.5 * acceleration.y ) - ( 0.5 * Gravity );
	for (int i = 0; i < static_bodies.size(); i++)
	{
		if (OverLap(static_bodies[i]))
		{
			Collision = true;
		}
	}
	if (Collision)
	{
		position.y = position.y - (velocity.y + ( 0.5 * acceleration.y ) - ( 0.5 * Gravity ));
		velocity.y = -velocity.y * Bounciness;
		OnFloor = true;
		Collision = false;
	}
	else {
		OnFloor = false;
	}
	//YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
}

void RigidBody2D::update_position(std::vector<StaticBody2D> static_bodies)
{
	update_vel();
	check_for_collisions_and_apply_acceleration(static_bodies);
}

void RigidBody2D::update_position()
{
	update_vel();
	position.x = position.x + velocity.x + ( 0.5 * acceleration.x );
	position.y = position.y + velocity.y + ( 0.5 * acceleration.y ) - ( 0.5 * Gravity );
}
