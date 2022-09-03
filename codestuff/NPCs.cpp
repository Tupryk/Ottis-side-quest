// NPCS

class NPC
{
public:
	NPC(std::string path, float pos_x, float pos_y, float pos_z, float anim_x, float anim_y, float anim_w, float anim_h, int frames);
	void draw();
private:
	Animation anim;
	Vertice2D position;
	int spf = 150; // seonds per frame
};

NPC::NPC(std::string path, float pos_x, float pos_y, float pos_z, float anim_x, float anim_y, float anim_w, float anim_h, int frames)
{
	anim.load("Assets/Img/"+path, anim_x, anim_y, anim_w, anim_h, false, frames);
	position.x = pos_x;
	position.y = pos_y;
	anim.zPos = pos_z;
}

void NPC::draw()
{
	anim.update(position, spf);
}

struct Cat : StaticBody2D
{
	Animation animation;
	InteractIcon IIcon;
	TextBox box;
	bool InteractKeyBuffer = false;
	bool ChatActivated = false;

	void init()
	{
		animation.load(resourcePath() + "Assets/Img/gonwalk.png", 40, 40, 40, 40, false, 7);
		IIcon.init(position, 6);
		box.init("CatFace");
		position.y = ScreenHeight*0.3 - 100;
	}
	void draw(StaticBody2D player)
	{
		if (OverLapOffset(player, 20, 20, 20, 20)) {
			IIcon.draw(position, true);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !InteractKeyBuffer)
			{
				ChatActivated = !ChatActivated;
				PlayerInteracting = !PlayerInteracting;
				InteractKeyBuffer = true;
			}
			else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				InteractKeyBuffer = false;
			}
		} else {
			IIcon.draw(position, false);
		}
		if (ChatActivated) {
			box.TakePlayerInput(cameraPos, 3, "I am the product of your conciouse mind. 8==D \n\n\nBruh? \n\n\nThe rinocerous is the gay yey");
		} else {
			box.reset();
		}
		animation.update(position, 150);
	}
};
