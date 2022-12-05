#include <iostream>
#include "app.h"

int main(int argc, char** argv)
{
	App app;
	if (argc > 1 && strcmp(argv[1], "mod") == 0)
		app.mod();
	else
		app.run();
	return 0;
}