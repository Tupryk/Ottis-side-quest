// g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include -o p -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11 app.cpp engineUI.cpp Physics/physics.cpp Entities/block.cpp Graphics/sprites.cpp World/game.cpp World/scene.cpp World/chapter.cpp Graphics/camera.cpp Entities/player.cpp Entities/background.cpp Entities/npc.cpp utils.cpp Interactions/indicators.cpp Entities/character.cpp Graphics/debug_utils.cpp Interactions/chat.cpp Graphics/text.cpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include "app.h"


int main(int argc, char** argv)
{
	srand(time(NULL));
	App app;
	if (argc > 1 && strcmp(argv[1], "mod") == 0)
		app.mod(argv[2]);
	else
		app.run();
	return 0;
}
