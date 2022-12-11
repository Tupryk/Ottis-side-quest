// g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include -o p -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system -std=c++11 app.cpp engineUI.cpp Physics/physics.cpp Entities/block.cpp Graphics/sprites.cpp World/game.cpp World/scene.cpp World/chapter.cpp Graphics/camera.cpp Entities/player.cpp Entities/background.cpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include "app.h"


int main(int argc, char** argv)
{
	App app;
	if (argc > 1 && strcmp(argv[1], "mod") == 0)
		app.mod(argv[2]);
	else
		app.run();
	return 0;
}
