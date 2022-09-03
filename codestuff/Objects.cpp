// OBJECTS

struct Ball : RigidBody2D
{
	StaticImage image;
	bool PickedUp = false;
	bool KeyBuffer = false;

	Ball()
	{
		image.load("Assets/Img/Ball.png", 0, 0, 2, 2, false);
		size.x = 2;
		size.y = 2;
		position.y = -100;
		Friction = 0.05;
		AirResistance = 0.005;
		Bounciness = 0.69;
	}
	void update_status(Player player)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && !KeyBuffer)
		{
			KeyBuffer = true;
			if (PickedUp) {
				player.SomethingInMouth = false;
				PickedUp = false;
			} else {
				if (OverLapOffset(player, 8, 8, 8, 8) && !player.SomethingInMouth)
				{
					player.SomethingInMouth = true;
					PickedUp = true;
				}
			}
		} else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::I) && KeyBuffer) {
			KeyBuffer = false;
		}
		if (PickedUp)
		{
			position.x = player.MouthPos().x;
			position.y = player.MouthPos().y + 1;
			velocity.x = player.velocity.x;
			velocity.y = player.velocity.y;
		}
	}
	void draw()
	{
		image.update(position);
	}
};