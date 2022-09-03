#include "WorldInteraction.h"

void Interaction::draw(int PosX, int PosY)
{
	if (PlayerPosX >= PosX-32 && PlayerPosX <= PosX+64 && PlayerPosY >= PosY-32 && PlayerPosY <= PosY+64)
	{
		sf::Time lastUpdate = AnimationTimer.getElapsedTime();
		if (lastUpdate.asMilliseconds() > 100)
		{
			if (FrameIndex >= InteractionFrames-1)
			{
				FrameIndex = 3;
			} else {
				FrameIndex++;
			}
			Interaction.setTexture(InteractionTexture[FrameIndex]);
			AnimationTimer.restart();
		}
		Interaction.setPosition(PosX, PosY-24);
		if (!activated)
		{
			window.draw(Interaction);
		}
		if (!InteractKeyBuffer)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		    {
		    	activated = !activated;
		    	InteractKeyBuffer = true;
		    }
		}
	} else {
		if (FrameIndex > 0)
		{
			if (FrameIndex > 3)
			{
				FrameIndex = 3;
			}
			sf::Time lastUpdate = AnimationTimer.getElapsedTime();
			if (lastUpdate.asMilliseconds() > 100)
			{
				FrameIndex--;
				Interaction.setTexture(InteractionTexture[FrameIndex]);
				AnimationTimer.restart();
			}
			Interaction.setPosition(PosX, PosY-24);
			window.draw(Interaction);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && activated)
	    {
	    	activated = false;
	    	InteractKeyBuffer = true;
	    }
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		InteractKeyBuffer = false;
	}
}

void Interaction::init()
{
	for (int i = 0; i < InteractionFrames; i++)
	{
		InteractionTexture[i].loadFromFile(resourcePath() + "Assets/Img/InteractionButton.png", sf::IntRect(16*i, 0, 16, 24));
	}
}

void Dialog::init()
{
	TextBoxTexture.loadFromFile(resourcePath() + "Assets/Img/TextBox.png", sf::IntRect(0, 0, 348, 100));
	TextBox.setTexture(TextBoxTexture);

	LeftFaceTexture.loadFromFile(resourcePath() + "Assets/Img/ottiface.png", sf::IntRect(0, 0, 64, 64));
	LeftFace.setTexture(LeftFaceTexture);
	RightFaceTexture.loadFromFile(resourcePath() + "Assets/Img/CatFace.png", sf::IntRect(0, 0, 64, 64));
	RightFace.setTexture(RightFaceTexture);

	buffer.loadFromFile(resourcePath() + "Assets/snd/bruh.wav");
	sound.setBuffer(buffer);

    font.loadFromFile(resourcePath() + "Assets/Fonts/pixeltupryk.ttf");
	text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(64);
    text.scale(0.08f, 0.08f);
    cursor.setFont(font);
    cursor.setFillColor(sf::Color::Black);
    cursor.setCharacterSize(64);
    cursor.scale(0.08f, 0.08f);
}

void Dialog::drawNPC(std::string dialog)
{
    if (LetterIndex < dialog.length())
    {
		sf::Time lastUpdate = SpellingTimer.getElapsedTime();
		if (lastUpdate.asMilliseconds() > 50)
		{
    		LetterIndex++;
    		sound.play();
    		text.setString(dialog.substr(0, LetterIndex));
    		SpellingTimer.restart();
    	}
    } else {
    	text.setString(dialog);
    }
	TextBox.setPosition(96 + CameraPos, (-ScreenHeight*0.5)+10);
    text.setPosition(116 + CameraPos, (-ScreenHeight*0.5)+30);
    window.draw(TextBox);
    window.draw(text);

    RightFace.setPosition(460 + CameraPos, (-ScreenHeight*0.5)+20);
    window.draw(RightFace);
}

void Dialog::drawPlayer(std::string dialog, int PossibleAwnsers)
{
	AwnserGiven = false;
	cursor.setString("> ");
    text.setString(dialog);

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
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			sound.play();
			AwnserGiven = true;
			KeyBuffer = true;
		}
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
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

	cursor.setPosition(105 + CameraPos, (-ScreenHeight*0.5)+30+(PlayerCursorPos*19));
	TextBox.setPosition(96 + CameraPos, (-ScreenHeight*0.5)+10);
    text.setPosition(116 + CameraPos, (-ScreenHeight*0.5)+30);
    window.draw(TextBox);
    window.draw(text);
    window.draw(cursor);
    
    LeftFace.setPosition(16 + CameraPos, (-ScreenHeight*0.5)+20);
    window.draw(LeftFace);
}

int Dialog::PlayerAwnser()
{
	return PlayerCursorPos;
}