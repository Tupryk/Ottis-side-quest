#include "NPCs.h"

void Person::draw()
{
	if (Waiting)
	{
		if (PickingUpBall)
		{
			FrameIndex = 4;
			Waiting = false;
		}
		if (ThrowingBall)
		{
			ThrowingBall = false;
			Waiting = false;
		}
	}
	sf::Time lastUpdate = AnimationTimer.getElapsedTime();
	if (lastUpdate.asMilliseconds() > 250)
	{
		if (PickingUpBall)
		{
			FrameIndex++;
			if (FrameIndex > 8)
			{
				PickingUpBall = false;
				Waiting = true;
				FrameIndex = 0;
			}
		}
		if (ThrowingBall)
		{
			FrameIndex++;
			if (FrameIndex > 3)
			{
				ThrowingBall = false;
				Waiting = true;
				FrameIndex = 0;
			}
		}
		AnimationTimer.restart();
	}
	Person.setTexture(PersonTexture[FrameIndex]);
	window.draw(Person);
}

void Person::init()
{
	for (int i = 0; i < PersonFrames; i++)
	{
		if (i < 4)
		{
			PersonTexture[i].loadFromFile(resourcePath() + "Assets/Img/PersonSpriteSheet.png", sf::IntRect(40*i, 0, 40, 40));
		} 
		else if (i < PersonFrames)
		{
			int j = i-4;
			PersonTexture[i].loadFromFile(resourcePath() + "Assets/Img/PersonSpriteSheet.png", sf::IntRect(40*j, 40, 40, 40));
		}
	}
	Person.setPosition(-100, 98);
}

void Seagull::init()
{
	for (int i = 0; i < SeagullFrames; i++)
	{
		SeagullTexture[i].loadFromFile(resourcePath() + "Assets/Img/seagullSpriteSheet.png", sf::IntRect(10*i, 10, 10, 10));
	}
	Seagull.setPosition(100, 128);
}

void Seagull::draw()
{
	sf::Time lastUpdate = AnimationTimer.getElapsedTime();
	if (lastUpdate.asMilliseconds() > 100)
	{
		FrameIndex++;
		if (FrameIndex >= SeagullFrames)
		{
			FrameIndex = 0;
		}
		AnimationTimer.restart();
	}
	Seagull.setTexture(SeagullTexture[FrameIndex]);
	window.draw(Seagull);
}

void Cat::init()
{
	for (int i = 0; i < CatFrames; i++)
	{
		CatTexture[i].loadFromFile(resourcePath() + "Assets/Img/CatSpriteSheet.png", sf::IntRect(12*i, 0, 12, 12));
	}
	Cat.setPosition(PosX, PosY);
	interactionButton.init();
	dialog.init();
}

void Cat::draw()
{
	interactionButton.draw(PosX-2, PosY);
	if (interactionButton.activated) {
		chat();
	} else {
		dialog.LetterIndex = 0;
	}
	sf::Time lastUpdate = AnimationTimer.getElapsedTime();
	if (lastUpdate.asMilliseconds() > 500)
	{
		FrameIndex++;
		if (FrameIndex >= CatFrames)
		{
			FrameIndex = 0;
		}
		AnimationTimer.restart();
	}
	Cat.setTexture(CatTexture[FrameIndex]);
	window.draw(Cat);
}

void Cat::chat()
{
	if (dialog.AwnserGiven == true)
	{
		switch (dialog.PlayerAwnser())
		{
			case 0:
			dialog.drawNPC("I'm doing fine, thanks");
			break;
			case 1:
			dialog.drawNPC("Nope");
			break;
			case 2:
			dialog.drawNPC("Yes?");
			break;
		}
	} else {
		dialog.drawPlayer("Hey, how are you doing? \n\n\nHave u seen my ball?\n\n\n...", 3);
	}
}