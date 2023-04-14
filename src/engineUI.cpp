#include "engineUI.h"


EngineUI::EngineUI(char* arg_game)
{
	if (arg_game)
		game = arg_game;

	// commands["help"] = &EngineUI::help;
	// commands["place"] = &EngineUI::placeObject;
	// commands["kill"] = &EngineUI::killObject;

	dogsay("bruh");
	std::cout << "Inizialized modder on game: " << game << std::endl;
}

void EngineUI::dogsay(std::string text)
{
	std::cout << "  ______________________________ \n";
	std::cout << " /                               \\\n";
	std::cout << "|  Welcome to the Tupryk Engine.  |\n";
	std::cout << "|      (For help type help)       |\n";
	std::cout << " \\_______________________________/\n";
	std::cout << " _                               \n";
	std::cout << "(_)                              \n";
	std::cout << "                                 \n";
	std::cout << "  O                              \n";
	std::cout << "   .   _-----_                   \n";
	std::cout << "    _/|U U   \\ \\                 \n";
	std::cout << "  /V :.       \\/         ___     \n";
	std::cout << "  \\_______    |         / _ \\    \n";
	std::cout << "   U    |     \\_________\\ \\/ |   \n";
	std::cout << "       /                     \\   \n";
	std::cout << "  ____|___./     _____./     /   \n";
	std::cout << " //__________/__/___________/    \n";
	std::cout << std::endl;
}

void EngineUI::help(std::string command)
{
	std::cout << "exit:     Exits the program." << std::endl;
	std::cout << "run:      Starts your game." << std::endl;
	std::cout << "place:    Places an entity on a the scene." << std::endl;
	std::cout << "kill:     removes an entity form scene." << std::endl;
	std::cout << "create:   Creates a new entity type." << std::endl;
	std::cout << "delete:   Deletes entity type." << std::endl;
	std::cout << "list:     Gives back list of requested data." << std::endl;
	std::cout << "info:     Gives back data of an entity." << std::endl;
	std::cout << "hop:      Displays your games and allows you to change to one." << std::endl;
	std::cout << "scene:    Displays your scenes and allows you to change to one." << std::endl;
	std::cout << "chapter:  Displays your chapters and allows you to change to one." << std::endl;
	std::cout << "where:    Tells you where you are located." << std::endl;
}

void EngineUI::invalid(std::string text)
{
	std::vector<std::string> possible_commands = {"exit", "help", "run", "place", "kill", "create", "delete", "list", "info", "switch"};
	std::sort(possible_commands.begin(), possible_commands.end(),
		std::bind(compareStrings, std::placeholders::_1, std::placeholders::_2, text));
	float prob = possible_commands[0].compare(text);

	std::cout << "Invalid input.";
	if (prob < 2)
		std::cout << "Did you mean \"" << possible_commands[0] << "\"?";
	std::cout << "\n";
}

int EngineUI::getInputs()
{
	while (1)
	{
		std::string u_input;
		std::cout << "-> ";
		getline(std::cin, u_input);

		std::string command = u_input.substr(0, u_input.find(" "));

		if (command.compare("exit") == 0)
			return 0;
		else if (command.compare("run") == 0)
			return 1;

		//commands[command]->second(u_input);

		invalid(u_input);
	}
}

void EngineUI::placeObject(std::string command)
{
	std::vector<std::string> attributes = split(command, ' ');
	std::string name = attributes[1];

	if (name.size() <= 0)
		std::cout << "place <entity_name> <x_coordinate> <y_coordinate> <z_coordinate>" << std::endl;

	float x = 0, y = 0, z = 0;
	try{
		if (attributes[2].size() > 0)
			x = std::stof(attributes[2]);
		if (attributes[3].size() > 0)
			y = std::stof(attributes[3]);
		if (attributes[4].size() > 0)
			z = std::stof(attributes[4]);
	} catch (const std::exception& e) {
		std::cout << "Invalid coordinates." << std::endl;
		std::cout << "Place follows the structure: name x, y, z." << std::endl;
	}

	std::cout << "Placed " << name << " at coordinates: (" << x << ", " << y << ", " << z << ")." << std::endl;
}

void EngineUI::killObject(std::string command)
{
	return;
}

void EngineUI::createType(std::string command)
{
	return;
}

void EngineUI::deleteType(std::string command)
{
	return;
}
