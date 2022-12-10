#include <iostream>

#include "app.h"
#include "engineUI.h"
#include "World/game.h"


void App::mod(char* arg_game)
{
	EngineUI engineUI(arg_game);

	if (engineUI.getInputs() == 1)
		run();
}

void App::run()
{
	Game game(360*4, 240*4);
    game.run();
}
