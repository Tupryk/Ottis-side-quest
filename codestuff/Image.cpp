//IMAGES AND ANIMATIONS

class StaticImage // To create an image, you first nedd to load the image (load()), and then you can update (update()) to display it.
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float ScaleX = 1;
	float ScaleY = 1;
	float width, height;
	bool flipped = false;
public:
	float zPos = 0;
	void load(std::string ImageDrirectory, float x, float y, float w, float h, bool Smooth);
	void setScale(float ScaleX, float ScaleY);
	void flip(bool flipIt);
	void update(Vertice2D position);
};

void StaticImage::load(std::string ImageDrirectory, float x, float y, float w, float h, bool Smooth)
{
	if (w == 0)
		texture.loadFromFile(ImageDrirectory);

	texture.loadFromFile(ImageDrirectory, sf::IntRect(x, y, w, h));
	texture.setSmooth(Smooth);
	sprite.setTexture(texture);
	width = w;
	height = h;
}

void StaticImage::setScale(float NewScaleX, float NewScaleY)
{
	ScaleX = NewScaleX;
	ScaleY = NewScaleY;
	sprite.setScale(ScaleX, ScaleY);
	width *= ScaleX;
	height *= ScaleY;
}

void StaticImage::flip(bool flipIt)
{
	if (flipIt) {
		sprite.setScale(-ScaleX, ScaleY);
		flipped = true;
	} else {
		sprite.setScale(ScaleX, ScaleY);
		flipped = false; }
}

void StaticImage::update(Vertice2D position)
{
	if (flipped) { sprite.setPosition(std::round(position.x+(cameraPos.x*zPos) + width*0.5), std::round(position.y+(cameraPos.y*zPos) - height*0.5));
	} else { sprite.setPosition(std::round(position.x+(cameraPos.x*zPos) - width*0.5), std::round(position.y+(cameraPos.y*zPos) - height*0.5)); }
	window.draw(sprite);
} /////////////////////////////////////////////////////////////IMAGES END///////////////////////////////////////////////////////////////////

class Animation // To create an animation, you first nedd to load the frames (load()), and then you can update (update()) to display it.
{
private:
	sf::Texture *texture;
	sf::Sprite sprite;
	sf::Clock Timer;
	float ScaleX = 1;
	float ScaleY = 1;
	float width, height; // for flipping the image
public:
	float zPos = 0;
	int Frames = 0;
	int FrameIndex = 0;
	bool flipped = false;
	void load(std::string ImageDrirectory, float x, float y, float w, float h, bool Smooth, int frames);
	void setScale(float ScaleX, float ScaleY);
	void flip(bool flipIt);
	void update(Vertice2D position, int spf);
	void reverse(Vertice2D position, int spf);
};

void Animation::load(std::string ImageDrirectory, float x, float y, float w, float h, bool Smooth, int frames)
{
	Frames = frames;
	texture = new sf::Texture[Frames];
	for (int i = 0; i < frames; i++)
	{
		texture[i].loadFromFile(ImageDrirectory, sf::IntRect(x+(w*i), y, w, h));
		texture[i].setSmooth(Smooth);
		sprite.setTexture(texture[i]);
	}
	width = w;
	height = h;
}

void Animation::setScale(float NewScaleX, float NewScaleY)
{
	ScaleX = NewScaleX;
	ScaleY = NewScaleY;
	sprite.setScale(ScaleX, ScaleY);
	width *= ScaleX;
	height *= ScaleY;
}

void Animation::flip(bool flipIt)
{
	if (flipIt) {
		sprite.setScale(-ScaleX, ScaleY);
		flipped = true;
	} else {
		sprite.setScale(ScaleX, ScaleY);
		flipped = false; }
}

void Animation::update(Vertice2D position, int spf)
{
	sf::Time lastUpdate = Timer.getElapsedTime();
	if (lastUpdate.asMilliseconds() > spf) {
		FrameIndex++;
		if (FrameIndex < Frames) {
			sprite.setTexture(texture[FrameIndex]);
		} else {
			FrameIndex = 0;
			sprite.setTexture(texture[FrameIndex]);
		}
		Timer.restart();
	}

	if (flipped) { sprite.setPosition(std::round(position.x+(cameraPos.x*zPos) + width*0.5), std::round(position.y+(cameraPos.y*zPos) - height*0.5));
	} else { sprite.setPosition(std::round(position.x+(cameraPos.x*zPos) - width*0.5), std::round(position.y+(cameraPos.y*zPos) - height*0.5)); }

	window.draw(sprite);
}
void Animation::reverse(Vertice2D position, int spf)
{
	sf::Time lastUpdate = Timer.getElapsedTime();
	if (lastUpdate.asMilliseconds() > spf) {
		FrameIndex--;
		if (FrameIndex >= 0) {
			sprite.setTexture(texture[FrameIndex]);
		} else {
			FrameIndex = Frames-1;
			sprite.setTexture(texture[FrameIndex]);
		}
		Timer.restart();
	}

	if (flipped) { sprite.setPosition(std::round(position.x + width*0.5), std::round(position.y - height*0.5));
	} else { sprite.setPosition(std::round(position.x - width*0.5), std::round(position.y - height*0.5)); }

	window.draw(sprite);
} //////////////////////////////////////////////////////ANIMATION END///////////////////////////////////////////////////////////////////