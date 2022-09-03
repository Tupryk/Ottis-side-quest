// WORLDINTERACTIONS

struct InteractIcon
{
	Animation idle_animation;
	Animation appear_animation;

	Vertice2D position;
	float OffSet;

	void init(Vertice2D newPosition, float YOffSet)
	{
		idle_animation.load(resourcePath() + "Assets/Img/InteractionButton.png", 48, 0, 16, 25, false, 8);
		appear_animation.load(resourcePath() + "Assets/Img/InteractionButton.png", 0, 0, 16, 25, false, 3);
		OffSet = -YOffSet - 13;
		position.y = newPosition.y + OffSet;
	}
	void draw(Vertice2D newPosition, bool activated)
	{
		position.y = newPosition.y + OffSet;
		if (activated && appear_animation.FrameIndex == appear_animation.Frames - 1)
		{
			idle_animation.update(position, 100);
		}
		else if (idle_animation.FrameIndex != 0)
		{
			idle_animation.reverse(position, 100);
		}
		else if (activated)
		{
			appear_animation.update(position, 100);
		}
		else if (appear_animation.FrameIndex != 0)
		{
			appear_animation.reverse(position, 100);
		}
	}
};

struct TextBox
{
	StaticImage box_image;
	StaticImage NPCface;
	StaticImage ottiface;
	Vertice2D position;
	int LetterIndex = 0;
	bool isNPC = false;
	int PlayerCursorPos = 0;
	bool KeyBuffer = false;

	sf::SoundBuffer buffer;
	sf::Sound sound;

	sf::Clock SpellingTimer;

	sf::Font font;
	sf::Text text;
	sf::Text cursor;

	void init()
	{
		box_image.load(resourcePath() + "Assets/Img/TextBox.png", 0, 0, 212, 64, false);
		ottiface.load(resourcePath() + "Assets/Img/ottiface.png", 0, 0, 64, 64, false);

		buffer.loadFromFile(resourcePath() + "Assets/snd/bruh.wav");
		sound.setBuffer(buffer);

	    font.loadFromFile(resourcePath() + "Assets/Fonts/pixeltupryk.ttf");
		text.setFont(font);
	    text.setFillColor(sf::Color::Black);
	    text.setCharacterSize(48);
	    text.scale(0.1f, 0.1f);
	    cursor.setFont(font);
	    cursor.setFillColor(sf::Color::Black);
	    cursor.setCharacterSize(48);
	    cursor.scale(0.1f, 0.1f);
	}
	void init(std::string ncpfacename)
	{
		box_image.load(resourcePath() + "Assets/Img/TextBox.png", 0, 0, 212, 64, false);
		NPCface.load(resourcePath() + "Assets/Img/" + ncpfacename + ".png", 0, 0, 64, 64, false);
		ottiface.load(resourcePath() + "Assets/Img/ottiface.png", 0, 0, 64, 64, false);
		isNPC = true;

		buffer.loadFromFile(resourcePath() + "Assets/snd/bruh.wav");
		sound.setBuffer(buffer);

	    font.loadFromFile(resourcePath() + "Assets/Fonts/pixeltupryk.ttf");
		text.setFont(font);
	    text.setFillColor(sf::Color::Black);
	    text.setCharacterSize(48);
	    text.scale(0.1f, 0.1f);
	    cursor.setFont(font);
	    cursor.setFillColor(sf::Color::Black);
	    cursor.setCharacterSize(48);
	    cursor.scale(0.1f, 0.1f);
	}
	void reset()
	{
		LetterIndex = 0;
	}
	void draw_text_simple(Vertice2D camera_position, std::string inputText)
	{
		position.x = camera_position.x;
		position.y = camera_position.y - ScreenHeight*0.5 + 37;
		position.x = std::round(position.x);
		position.y = std::round(position.y);
		box_image.update(position);

		if (LetterIndex < inputText.length())
	    {
			sf::Time lastUpdate = SpellingTimer.getElapsedTime();
			if (lastUpdate.asMilliseconds() > 50)
			{
	    		LetterIndex++;
	    		sound.play();
	    		text.setString(inputText.substr(0, LetterIndex));
	    		SpellingTimer.restart();
	    	}
	    } else {
	    	text.setString(inputText);
	    }
	    text.setPosition(position.x - 94, position.y - 20);
	    window.draw(text);

	    if (isNPC)
	    {
	    	position.x = camera_position.x + ScreenWidth*0.5 - 37;
			position.x = std::round(position.x);
	    	NPCface.update(position);
	    }
	}
	int TakePlayerInput(Vertice2D camera_position, int PossibleAwnsers, std::string Options)
	{
		position.x = camera_position.x;
		position.y = camera_position.y - ScreenHeight*0.5 + 37;
		position.x = std::round(position.x);
		position.y = std::round(position.y);
		box_image.update(position);

		cursor.setString("> ");
	    text.setString(Options);

		if (!KeyBuffer)
		{
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		    {
		    	sound.play();
		    	PlayerCursorPos++;
		    	KeyBuffer = true;
		    }
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		    {
		    	sound.play();
		    	PlayerCursorPos--;
		    	KeyBuffer = true;
		    }
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			KeyBuffer = false;
		}
		if (PlayerCursorPos < 0)
		{
			PlayerCursorPos = 0;
		}
		if (PlayerCursorPos >= PossibleAwnsers)
		{
			PlayerCursorPos = PossibleAwnsers-1;
		}

		text.setPosition(position.x - 90, position.y - 20);
		cursor.setPosition(position.x - 99, position.y - 20 + (PlayerCursorPos*17));
	    window.draw(text);
	    window.draw(cursor);
	    
	    position.x = camera_position.x - ScreenWidth*0.5 + 37;
		position.x = std::round(position.x);
    	ottiface.update(position);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			sound.play();
			return PlayerCursorPos;
			KeyBuffer = true;
		} else {
			return -1;
		}
	}
};