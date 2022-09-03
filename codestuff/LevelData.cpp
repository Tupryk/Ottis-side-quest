struct LevelData
{
	std::vector<StaticBody2D> static_bods;
	std::vector<RigidBody2D> rigid_bods;
};

struct Level0 : LevelData
{
	Level0()
	{
		/*
		Player player;
		Floor floor[3];
		StaticBody2DList static_bodies;
		Ball ball;
		Title title;

	    floor[0].init();
	    floor[1].init();
	    floor[2].init();
	    floor[1].position.x = -ScreenWidth*0.5 + 100 + floor[1].size.x;
	    floor[1].position.y = ScreenHeight*0.3 + 50;
	    floor[2].position.x = -ScreenWidth*0.5 + 100 - floor[2].size.x;
	    floor[2].position.y = ScreenHeight*0.3 - 15;
	    title.init();

	    static_bods.push_back(floor[0]);
	    static_bods.push_back(floor[1]);
	    static_bods.push_back(floor[2]);

	    rigid_bods.push_back(player);
	    rigid_bods.push_back(title);
	    rigid_bods.push_back(ball);
	    */
	}
};