#ifndef GAME
#define GAME

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "chapter.h"


class Game
{
	int width;
	int height;
	std::string title;
	std::string icon_path;
	Chapter chapter;

public:
	Game(unsigned int width, unsigned int height, std::string title = "Tupryk Engine", std::string icon_file = "icon.png");
	void run();
};


#endif
