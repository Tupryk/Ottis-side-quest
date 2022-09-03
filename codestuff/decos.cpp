class deco
{
public:
	deco(std::string path, float pos_x, float pos_y, float pos_z);
	void draw();
private:
	StaticImage image;
	Vertice2D position;
};

deco::deco(std::string path, float pos_x, float pos_y, float pos_z)
{
	image.load("Assets/Img/"+path, 0, 0, 0, 0, false);
	position.x = pos_x;
	position.y = pos_y;
	image.zPos = pos_z;
}

void deco::draw()
{
	image.update(position);
}

class liveDeco
{
public:
	liveDeco(std::string path, float pos_x, float pos_y, float pos_z);
	void draw();
private:
	Animation anim;
	Vertice2D position;
};

class Backround
{
private:
	std::vector<deco> d;
	std::vector<liveDeco> ld;
public:
	//Backround(LevelDecoData lvldt);
	void draw();
};

void Backround::draw()
{
	for (auto i : d)
		i.draw();
	//for (auto i : ld)
		//i.draw();
}