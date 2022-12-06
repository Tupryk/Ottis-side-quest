#include <iostream>


void dogsay(std::string text)
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

void help()
{
	std::cout << "exit: Exits the program." << std::endl;
}

void invalid(std::string text)
{
	std::cout << "Invalid input.";
	float prob = 0.1;
	if (prob < 0.11) {
		std::string meant = "bruh";
		std::cout << "Did you mean \"" << meant << "\"?";
	}
	std::cout << "\n";
}