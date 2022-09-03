// MOBS

struct DuckGuy : RigidBody2D
{
	Animation idle_animation;
	Animation walk_animation;
	Animation attack_animation;
	Animation jump_animation;
	Animation hurt_animation;

	int health = 300;
	float Speed = 0.1;
	float JumpStrength = 7;
	bool Active = true;
	bool Attacking = false;
	bool Hurt = false;
	bool HurtBuffer = false;
	bool JumpBuffer = false;

	StaticBody2D UpperView;
	StaticBody2D FrontView;
	StaticBody2D LowerView;
	StaticBody2D BackView;


	void init()
	{
		idle_animation.load(resourcePath() + "Assets/Img/Enemy.png", 0, 0, 16, 16, false, 4);
		walk_animation.load(resourcePath() + "Assets/Img/Enemy.png", 0, 16, 16, 16, false, 4);
		attack_animation.load(resourcePath() + "Assets/Img/Enemy.png", 0, 32, 16, 16, false, 4);
		jump_animation.load(resourcePath() + "Assets/Img/Enemy.png", 0, 0, 16, 16, false, 4);
		hurt_animation.load(resourcePath() + "Assets/Img/Enemy.png", 0, 48, 16, 16, false, 1);
		size.x = 16;
		size.y = 16;
		position.x = 100;

		UpperView.size.x = 16;
		UpperView.size.y = 16;
		FrontView.size.x = 16;
		FrontView.size.y = 16;
		LowerView.size.x = 16;
		LowerView.size.y = 16;
		BackView.size.x = 16;
		BackView.size.y = 16;

		UpperView.position.x = position.x - UpperView.size.x;
		UpperView.position.y = position.y - UpperView.size.y;
		FrontView.position.x = position.x - FrontView.size.x;
		FrontView.position.y = position.y;
		LowerView.position.x = position.x - LowerView.size.x;
		LowerView.position.y = position.y + LowerView.size.y;
		BackView.position.x = position.x + BackView.size.x;
		BackView.position.y = position.y;
	}
	void updateHealth(Player player)
	{
		if (player.isAttacking)
		{
			if (OverLapOffset(player, 10, 0, 10, 0))
			{
				if (!HurtBuffer)
				{
					HurtBuffer = true;
					health -= 20;
					Hurt = true;
					if (player.position.x > position.x)
					{
						acceleration.x = -1;
					} else {
						acceleration.x = 1;
					}
				}
			} else {
				HurtBuffer = false;
			}
		} else {
			Hurt = false;
			acceleration.x = 0;
			acceleration.y = 0;
		}
		if (position.y >= 1000)
		{
			health = 0;
		}
		if (health <= 0)
		{
			position.x = 0;
			position.y = -100;
			health = 300;
		}
	}
	void updateAttack(Player player, StaticBody2DList static_bodies)
	{
		if (idle_animation.flipped)
		{
			UpperView.position.x = position.x + UpperView.size.x;
			UpperView.position.y = position.y - UpperView.size.y;
			FrontView.position.x = position.x + FrontView.size.x;
			FrontView.position.y = position.y;
			LowerView.position.x = position.x + LowerView.size.x;
			LowerView.position.y = position.y + LowerView.size.y;
			BackView.position.x = position.x - BackView.size.x;
			BackView.position.y = position.y;
		} else {
			UpperView.position.x = position.x - UpperView.size.x;
			UpperView.position.y = position.y - UpperView.size.y;
			FrontView.position.x = position.x - FrontView.size.x;
			FrontView.position.y = position.y;
			LowerView.position.x = position.x - LowerView.size.x;
			LowerView.position.y = position.y + LowerView.size.y;
			BackView.position.x = position.x + BackView.size.x;
			BackView.position.y = position.y;
		}
		if (FrontView.OverLap(player)) {
			Active = false;
			Attacking = true;
		} else {
			Active = true;
			Attacking = false;
		}
		if (Active)
		{
			bool SomethingInFront = false;
			bool SomethingDown = false;
			bool SomethingUp = false;
			for (int i = 0; i < static_bodies.Amount; i++)
			{
				if (FrontView.OverLap(static_bodies.static_body[i]))
				{
					SomethingInFront = true;
				}
				if (LowerView.OverLap(static_bodies.static_body[i]))
				{
					SomethingDown = true;
				}
				if (UpperView.OverLap(static_bodies.static_body[i]))
				{
					SomethingUp = true;
				}
			}
			if (player.position.x > position.x) { // Go Right
				idle_animation.flip(true);
				walk_animation.flip(true);
				attack_animation.flip(true);
				jump_animation.flip(true);
				hurt_animation.flip(true);
				if (!SomethingInFront && SomethingDown) {
					acceleration.x = Speed;
					acceleration.y = 0;
				} else if (SomethingInFront && !SomethingUp) {
					acceleration.x = Speed * 10;
					if (OnFloor && !JumpBuffer) {
						acceleration.y = -JumpStrength;
						JumpBuffer = true;
					} else if (OnFloor) {
						JumpBuffer = false;
					}
				} else {
					Active = false;
					acceleration.y = 0;
				}
			} else { // Go Left
				idle_animation.flip(false);
				walk_animation.flip(false);
				attack_animation.flip(false);
				jump_animation.flip(false);
				hurt_animation.flip(false);
				if (!SomethingInFront && SomethingDown) {
					acceleration.x = -Speed;
					acceleration.y = 0;
				} else if (SomethingInFront && !SomethingUp) {
					acceleration.x = -Speed * 10;
					if (OnFloor && !JumpBuffer) {
						acceleration.y = -JumpStrength;
						JumpBuffer = true;
					} else if (OnFloor) {
						JumpBuffer = false;
					}
				} else {
					Active = false;
					acceleration.y = 0;
				}
			}
		} else if (Attacking) {
			acceleration.y = 0;
		}
	}
	void draw()
	{
		if (!Attacking) {
			attack_animation.FrameIndex = 0;
		if (Hurt) {
			hurt_animation.update(position, 150);
		} else if (!OnFloor) {
			jump_animation.update(position, 150);
		} else if (Active) {
			walk_animation.update(position, 150);
		} else {
			idle_animation.update(position, 150); }
		} else {
			attack_animation.update(position, 300);
		}
		/*
		drawSquare(FrontView, sf::Color::Red);
		drawSquare(UpperView, sf::Color::Green);
		drawSquare(LowerView, sf::Color::Yellow);
		drawSquare(BackView, sf::Color::Blue);
		*/
	}
};