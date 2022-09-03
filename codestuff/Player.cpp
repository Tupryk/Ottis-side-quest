// PLAYER

struct Player : RigidBody2D
{
	Animation idle_animation;
	Animation walk_animation;
	Animation run_animation;
	Animation jump_animation;

	Animation attack_wave;
	Vertice2D attack_wave_position;

	BloodParticles blood;

	const float Speed = 1;
	const float JumpStrength = 10;
	int health = 100;
	bool isAttacking = false;
	bool AttackKeyBuffer = false;
	bool SomethingInMouth = false;
	bool HurtBuffer = false;
	bool JumpBuffer = false;

	Player();
	void hurt(int damage, bool FromLeft);
	void updateHealth();
	void draw();
	void TakePlayerInput();
	std::string animation_state();

	Vertice2D MouthPos();
};

Player::Player()
{
	idle_animation.load("Assets/Img/OttiSpriteSheet.png", 0, 0, 16, 16, false, 1);
	walk_animation.load("Assets/Img/OttiSpriteSheet.png", 0, 0, 16, 16, false, 9);
	run_animation.load("Assets/Img/OttiSpriteSheet.png", 0, 16, 16, 16, false, 12);
	jump_animation.load("Assets/Img/OttiSpriteSheet.png", 0, 32, 16, 16, false, 9);

	attack_wave.load("Assets/Img/OttiAttack.png", 0, 0, 8, 8, false, 6);
	attack_wave_position.x = position.x + 8;
	attack_wave_position.y = position.y;
	
	size.x = 16;
	size.y = 16;

	blood.init(position);
}

void Player::updateHealth()
{
	if (position.y >= 1000)
	{
		health = 0;
	}
	if (health <= 0)
	{
		position.x = 0;
		position.y = -100;
		health = 100;
	}
}

void Player::hurt(int damage, bool FromLeft)
{
	if (!HurtBuffer && !PlayerInteracting)
	{
		HurtBuffer = true;
		health -= damage;
		blood.init(position);
		if (FromLeft) {
			acceleration.x = -1;
		} else {
			acceleration.x = 1;
		}
	}
}

void Player::draw()
{
	std::string animation = animation_state();
	if (animation == "Jumping")
	{
		jump_animation.update(position, 100);
	}
	else if (animation == "Running")
	{
		run_animation.update(position, 100); //Speed of animation determined by x velocity
		jump_animation.FrameIndex = 0;	
	}
	else if (animation == "Walking")
	{
		walk_animation.update(position, 100);
		jump_animation.FrameIndex = 0;
	}
	else // Falling?
	{
		idle_animation.update(position, 100);
		jump_animation.FrameIndex = 0;
	}

	if (isAttacking)
	{
		if (attack_wave.flipped) {
			attack_wave_position.x = position.x - 10;
		} else {
			attack_wave_position.x = position.x + 10; }
		attack_wave_position.y = position.y - 2;
		attack_wave.update(attack_wave_position, 15);
		if (attack_wave.FrameIndex == attack_wave.Frames-4)
		{
			isAttacking = false;
		}
	}
	blood.update(position);
	blood.draw();
}

void Player::TakePlayerInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			acceleration.x = Speed;
		} else {
			acceleration.x = Speed * 0.5;
		}
		idle_animation.flip(false);
		walk_animation.flip(false);
		run_animation.flip(false);
		jump_animation.flip(false);

		attack_wave.flip(false);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			acceleration.x = -Speed;
		} else {
			acceleration.x = -Speed * 0.5;
		}
		idle_animation.flip(true);
		walk_animation.flip(true);
		run_animation.flip(true);
		jump_animation.flip(true);

		attack_wave.flip(true);
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		acceleration.x = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && OnFloor && !JumpBuffer)
	{
		acceleration.y = -JumpStrength;
		JumpBuffer = true;
	} else if (OnFloor && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		acceleration.y = 0;
		JumpBuffer = false;
	} else {
		acceleration.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && !isAttacking && !AttackKeyBuffer && !SomethingInMouth) {
		isAttacking = true;
		AttackKeyBuffer = true;
	} else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::K) && AttackKeyBuffer) {
		AttackKeyBuffer = false;
	}
}

std::string Player::animation_state()
{
	if (velocity.y < 0)
	{
		return "Jumping";
	}
	else if (velocity.x > 7 || velocity.x < -7)
	{
		return "Running";
	}
	else if (velocity.x > 1 || velocity.x < -1)
	{
		return "Walking";
	}
	return "Idle";
}

Vertice2D Player::MouthPos()
{
	Vertice2D newMouthPos;
	std::string animationState = animation_state();
	if (animationState == "Jumping") {
		switch(jump_animation.FrameIndex)
		{
			case 0:
			newMouthPos.x = 6;
			newMouthPos.y = -4;
			break;
			case 1:
			newMouthPos.x = 6;
			newMouthPos.y = -5;
			break;
			case 2:
			newMouthPos.x = 6;
			newMouthPos.y = -6;
			break;
			case 3:
			newMouthPos.x = 7;
			newMouthPos.y = -3;
			break;
			case 4:
			newMouthPos.x = 7;
			newMouthPos.y = -1;
			break;
		}
	} else if (animationState == "Falling") {
		switch(jump_animation.FrameIndex)
		{
			case 0:
			newMouthPos.x = 7;
			newMouthPos.y = -2;
			break;
			case 1:
			newMouthPos.x = 7;
			newMouthPos.y = -1;
			break;
			case 2:
			newMouthPos.x = 7;
			newMouthPos.y = 0;
			break;
			case 3:
			newMouthPos.x = 7;
			newMouthPos.y = 1;
			break;
		}
	} else if (animationState == "Running") {
		switch(run_animation.FrameIndex)
		{
			case 0:
			newMouthPos.x = 7;
			newMouthPos.y = 0;
			break;
			case 1:
			newMouthPos.x = 8;
			newMouthPos.y = -2;
			break;
			case 2:
			newMouthPos.x = 8;
			newMouthPos.y = -2;
			break;
			case 3:
			newMouthPos.x = 8;
			newMouthPos.y = 0;
			break;
			case 4:
			newMouthPos.x = 8;
			newMouthPos.y = -1;
			break;
			case 5:
			newMouthPos.x = 7;
			newMouthPos.y = -1;
			break;
			case 6:
			newMouthPos.x = 7;
			newMouthPos.y = -2;
			break;
			case 7:
			newMouthPos.x = 8;
			newMouthPos.y = -3;
			break;
			case 8:
			newMouthPos.x = 8;
			newMouthPos.y = -3;
			break;
			case 9:
			newMouthPos.x = 7;
			newMouthPos.y = -2;
			break;
			case 10:
			newMouthPos.x = 7;
			newMouthPos.y = -2;
			break;
			case 11:
			newMouthPos.x = 7;
			newMouthPos.y = -1;
			break;
		}
	} else { //Walking
		switch(walk_animation.FrameIndex)
		{
			case 0:
			newMouthPos.x = 7;
			newMouthPos.y = -2;
			break;
			case 1:
			newMouthPos.x = 7;
			newMouthPos.y = -2;
			break;
			case 2:
			newMouthPos.x = 7;
			newMouthPos.y = -2;
			break;
			case 3:
			newMouthPos.x = 7;
			newMouthPos.y = -1;
			break;
			case 4:
			newMouthPos.x = 7;
			newMouthPos.y = -1;
			break;
			case 5:
			newMouthPos.x = 7;
			newMouthPos.y = -1;
			break;
			case 6:
			newMouthPos.x = 7;
			newMouthPos.y = -2;
			break;
			case 7:
			newMouthPos.x = 7;
			newMouthPos.y = -2;
			break;
			case 8:
			newMouthPos.x = 7;
			newMouthPos.y = -2;
			break;
		}
	}
	if (idle_animation.flipped)
	{
		newMouthPos.x = -newMouthPos.x;
	}
	newMouthPos.x = newMouthPos.x + position.x;
	newMouthPos.y = newMouthPos.y + position.y;
	return newMouthPos;
}