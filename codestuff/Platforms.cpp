// PLATFORMS

class Platform : public StaticBody2D
{
private:
	StaticImage image;
public:
	Platform(float size_x, float size_y, float pos_x, float pos_y, std::string texture, float depth)
	{
		if (texture != "")
			image.load("Assets/Img/"+texture, 0, 0, size_x, size_y, false);

		position.x = pos_x;
		position.y = pos_y;
		size.x = size_x;
		size.y = size_y-depth;
	}
	void draw() { image.update(position); };
};

/*
class Backround : image
{
	StaticImage image;
	void init()
	{
		image.load(resourcePath() + "Assets/Img/Title.png", 0, 0, 256, 128, false);
		position.x = -ScreenWidth*0.5 + 100;
	    position.y = -1000;
	    size.x = 256;
	    size.y = 128;
	    Bounciness = 1;
	    image.zPos = 0.5;
	}
	void draw()
	{
		image.update(position);
	}
};
*/