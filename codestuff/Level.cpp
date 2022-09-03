class Level
{
private:
	std::vector<StaticBody2D> objects; // objects are in desc zPos order
	std::vector<RigidBody2D*> rigid_bods;
public:
	Level();
	void update();
	void draw();
};

void Level::update()
{
	for (auto obj : rigid_bods) {
		obj->update(static_bodies);
	}
}

void Level::draw()
{
	for (auto obj : objects) {
		obj->draw();
	}
}