#include <iostream>
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
