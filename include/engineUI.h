#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

#include "utils.h"


class EngineUI
{
	std::map<std::string, std::function<int(int)>> commands;
	std::string u_input;

	std::string game;
	std::string chapter;
	std::string scene;

	void dogsay(std::string text);
	void invalid(std::string text);
	void help(std::string command);
	void placeObject(std::string command);
	void killObject(std::string command);
	void createType(std::string command);
	void deleteType(std::string command);

public:
	EngineUI(char* arg_game);
	int getInputs();
};
