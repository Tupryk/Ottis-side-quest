// WORLD

class World
{
	Camera camera;

	Player player;
	Platform plat;
	Ball ball;
	deco van1;
	deco car;
	NPC gon;
	deco cart;
	deco van2;
	deco tree;

	std::vector<StaticBody2D> static_bodies;
public:
	World() :	tree("gon_scene/tree.png", -250, -200, 0.65),
				plat(5120, 124, 0, 150, "", 32),
				van2("gon_scene/back_van.png", -65, -70, 0.7),
				cart("gon_scene/shopping_cart.png", -100, 30, 0.5),
				gon("gon_scene/gonwalk.png", 125, 25, 0.6, 40, 40, 40, 40, 7),
				car("gon_scene/car.png", 100, -20, 0.6),
				van1("gon_scene/front_van.png", -250, -15, 0.5) {
		static_bodies.push_back(plat);
	}
	void update();
};

void World::update()
{
	// Update random stuff
	player.SomethingInMouth = ball.PickedUp;

	// Physics update
	player.update_position(static_bodies);
	ball.update_position(static_bodies);

	// Update random stuff
	player.updateHealth();
	ball.update_status(player);

	// Update camera
    //camera.update_dynamic(player);
    camera.update_static(player);
    cameraPos.x = camera.position.x;
    cameraPos.y = camera.position.y;

    // Update Input
    if (!PlayerInteracting) {
    	player.TakePlayerInput();
    } else {
    	player.acceleration.x = 0;
    	player.acceleration.y = 0;
    	player.velocity.x = 0;
    	player.velocity.y = 0;
    }

    // Draw things
    van2.draw();
    tree.draw();
    car.draw();
    gon.draw();
    van1.draw();
    cart.draw();
    plat.draw();
    player.draw();
    ball.draw();
}

/*
class World
{
	Player player;
	Cat cat;
	Floor floor[3];
	StaticBody2DList static_bodies;
	DuckGuy duck;
	Ball ball;
	Title title;

	Camera camera;
	bool defined = false;
public:
	void update();
};

void World::update()
{
	if (!defined)
	{
	    cat.init();
	    camera.init();
	    duck.init();
	    ball.init();
	    floor[0].init();
	    floor[1].init();
	    floor[2].init();
	    floor[1].position.x = -ScreenWidth*0.5 + 100 + floor[1].size.x;
	    floor[1].position.y = ScreenHeight*0.3 + 50;
	    floor[2].position.x = -ScreenWidth*0.5 + 100 - floor[2].size.x;
	    floor[2].position.y = ScreenHeight*0.3 - 15;
	    title.init();

	    static_bodies.init(3);
	    static_bodies.add_body(floor[0]);
	    static_bodies.add_body(floor[1]);
	    static_bodies.add_body(floor[2]);
	    defined = true;
	}

	if (duck.Attacking && duck.attack_animation.FrameIndex == 2 && (duck.FrontView.OverLap(player) || duck.OverLap(player)))
	{
		if (player.position.x > duck.position.x) {
			player.hurt(20, false);
		} else {
			player.hurt(20, true);
		}
	} else {
		player.HurtBuffer = false;
	}

	player.SomethingInMouth = ball.PickedUp;
	player.update_position(static_bodies);
	duck.update_position(static_bodies);
	ball.update_position(static_bodies);
	title.update_position(static_bodies);

	player.updateHealth();
	duck.updateHealth(player);
	ball.update_status(player);
	duck.updateAttack(player, static_bodies);

    camera.update(player);
    cameraPos.x = camera.position.x;
    cameraPos.y = camera.position.y;
    
    title.draw();
    floor[0].draw();
    floor[1].draw();
    floor[2].draw();
    cat.draw(player);
    duck.draw();
    player.draw();
    ball.draw();

    if (!PlayerInteracting) {
    	player.TakePlayerInput();
    } else {
    	player.acceleration.x = 0;
    	player.acceleration.y = 0;
    	player.velocity.x = 0;
    	player.velocity.y = 0;
    }
}
*/
