/*#include <iostream>
#include "app.h"

int main(int argc, char** argv)
{
	App app;
	if (argc > 1 && strcmp(argv[1], "mod") == 0)
		app.mod(argv[2]);
	else
		app.run();
	return 0;
}*/

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
