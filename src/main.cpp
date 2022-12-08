// g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include -o p -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
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
