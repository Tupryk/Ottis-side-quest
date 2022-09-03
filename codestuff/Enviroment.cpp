#include "Enviroment.h"

void Backround::draw()
{
	sf::Time lastUpdate = AnimationTimer.getElapsedTime();
	if (lastUpdate.asMilliseconds() > 750)
	{
		if (GoingUp)
		{
			FrameIndex--;
			if (FrameIndex < 0)
			{
				FrameIndex = 0;
				GoingUp = false;
			}
		} else {
			FrameIndex++;
			if (FrameIndex > 1)
			{
				FrameIndex = 1;
				GoingUp = true;
			}
		}
		AnimationTimer.restart();
	}
	Layer[0].setTexture(Layer0Texture[FrameIndex]);
	Layer[1].setTexture(Layer1Texture[FrameIndex]);
	Layer[2].setTexture(Layer2Texture[FrameIndex]);
	Layer[3].setTexture(Layer3Texture[FrameIndex]);

	Layer[0].setPosition(-ScreenWidth*0.5, 108);
	window.draw(Layer[0]);
	Layer[0].setPosition(-ScreenWidth*0.5+540, 108);
	window.draw(Layer[0]);

	Layer[1].setPosition(static_cast<int>((-ScreenWidth*0.5*540/LevelLength)+(CameraPos*0.5))+(-ScreenWidth*0.5), 58);
	window.draw(Layer[1]);
	Layer[1].setPosition(static_cast<int>((-ScreenWidth*0.5*540/LevelLength)+(CameraPos*0.5))+540+(-ScreenWidth*0.5), 58);
	window.draw(Layer[1]);

	Layer[2].setPosition(static_cast<int>((-ScreenWidth*0.5*540/LevelLength)+(CameraPos*0.75))+(-ScreenWidth*0.5), 38);
	window.draw(Layer[2]);
	Layer[2].setPosition(static_cast<int>((-ScreenWidth*0.5*540/LevelLength)+(CameraPos*0.75))+540+(-ScreenWidth*0.5), 38);
	window.draw(Layer[2]);

	Layer[3].setPosition(static_cast<int>((-ScreenWidth*0.5*540/LevelLength)+CameraPos*0.9)+(-ScreenWidth*0.5), 23);
	window.draw(Layer[3]);
	Layer[3].setPosition(static_cast<int>((-ScreenWidth*0.5*540/LevelLength)+CameraPos*0.9)+540+(-ScreenWidth*0.5), 23);
	window.draw(Layer[3]);
}

void Backround::init()
{
	for (int i = 0; i < 3; i++)
	{
		Layer0Texture[i].loadFromFile(resourcePath() + "Assets/Img/beachAnim.png", sf::IntRect(0, (157*i)+85, 540, 72));
	}
	for (int i = 0; i < 3; i++)
	{
		Layer1Texture[i].loadFromFile(resourcePath() + "Assets/Img/beachAnim.png", sf::IntRect(0, (157*i)+35, 540, 50));
	}
	for (int i = 0; i < 3; i++)
	{
		Layer2Texture[i].loadFromFile(resourcePath() + "Assets/Img/beachAnim.png", sf::IntRect(0, (157*i)+15, 540, 20));
	}
	for (int i = 0; i < 3; i++)
	{
		Layer3Texture[i].loadFromFile(resourcePath() + "Assets/Img/beachAnim.png", sf::IntRect(0, 157*i, 540, 15));
	}
}

void BackroundImg::draw()
{
	Backround.setPosition(CameraPos, -ScreenHeight*0.5);
	Faro.setPosition(static_cast<int>(CameraPos*0.999)+57, -ScreenHeight*0.5+177);
	window.draw(Backround);
	window.draw(Faro);
}

void BackroundImg::init()
{
	BackroundImg.loadFromFile(resourcePath() + "Assets/Img/Backround1.png", sf::IntRect(0, 0, 540, 360));
	Backround.setTexture(BackroundImg);
	FaroTex.loadFromFile(resourcePath() + "Assets/Img/Faro.png", sf::IntRect(0, 0, 98, 26));
	Faro.setTexture(FaroTex);
}

void Clouds::init()
{
	for (int i = 0; i < CloudsAmount; i++)
	{
		CloudTexture[i].loadFromFile(resourcePath() + "Assets/Img/clouds-v21.png", sf::IntRect(0, 0, 155, 74));
		Cloud[i].setTexture(CloudTexture[i]);

		if (i != 0){
			PosX[i] = PosX[i-1] + (rand()%100) + 150;
		} else {
			PosX[i] = 200 + (rand()%100);
		}
		PosY[i] = ((rand()%50)*-1)-120;
		Vel[i] = (rand()%50)*0.01;
	}
}

void Clouds::draw()
{
	for (int i = 0; i < CloudsAmount; i++)
	{
		Cloud[i].setPosition(static_cast<int>((PosX[i]*540/1000)+(CameraPos*0.99)), static_cast<int>(PosY[i]));
		window.draw(Cloud[i]);
	}
}

void Clouds::update()
{
	for (int i = 0; i < CloudsAmount; i++)
	{
		if (PosX[i] < -ScreenWidth*0.5-150)
		{
			if (i != 0){
				PosX[i] = PosX[i-1] + (rand()%100);
			} else {
				PosX[i] = 200 + (rand()%100);
			}
			PosY[i] = ((rand()%100)*-1)-100;
		}
	}
	sf::Time lastUpdate = CloudUpdater.getElapsedTime();
	if (lastUpdate.asMilliseconds() > 100)
	{
		for (int i = 0; i < CloudsAmount; i++)
		{
			PosX[i] -= Vel[i];
		}
		CloudUpdater.restart();
	}
}

void Boat::init()
{
	BoatTexture.loadFromFile(resourcePath() + "Assets/Img/boat.png", sf::IntRect(0, 0, 16, 32));
	Boat.setTexture(BoatTexture);
}

void Boat::draw()
{
	sf::Time lastUpdate = MovementTimer.getElapsedTime();
	if (lastUpdate.asMilliseconds() > 250)
	{
		PosX += Speed;
		if (PosX > LevelLength)
		{
			PosX = (-ScreenWidth*0.5)-16;
		}
		MovementTimer.restart();
	}
	Boat.setPosition(static_cast<int>((PosX*540/LevelLength)+CameraPos*0.9)+540+(-ScreenWidth*0.5), 15);
	window.draw(Boat);
}

void Plataform::init()
{
	Piece1Texture.loadFromFile(resourcePath() + "Assets/Img/PlataformPiece1.png", sf::IntRect(0, 0, 339, 161));
	Piece1.setTexture(Piece1Texture);
	Piece1.setPosition(-ScreenWidth*0.5+LevelLength-339, ScreenHeight*0.5-161);
	Piece2Texture.loadFromFile(resourcePath() + "Assets/Img/PlataformPiece2.png", sf::IntRect(0, 0, 339, 161));
	Piece2.setTexture(Piece2Texture);
	Piece2.setPosition(-ScreenWidth*0.5+LevelLength-339, ScreenHeight*0.5-161);
}

void Plataform::drawBack()
{
	window.draw(Piece1);
}

void Plataform::drawFront()
{
	window.draw(Piece2);
}