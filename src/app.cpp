#include <iostream>
#include "app.h"
#include "engineUI.h"


void App::mod()
{
	dogsay("");
	while (1)
	{
		std::string u_input;
		std::cout << "-> ";
		std::cin >> u_input;
		if (u_input.compare("exit") == 0)
			break;
		else if (u_input.compare("help") == 0)
			help();
		else
		 	invalid(u_input);
	}
}

void App::run()
{
	std::cout << ":Running Game:" << std::endl; 
}
