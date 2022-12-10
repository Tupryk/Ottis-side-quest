#include "game.h"
#include "scene.h"


Game::Game(unsigned int width, unsigned int height, std::string title, std::string icon_file)
{
	this->width = width;
	this->height = height;
	this->title = title;
	this->icon_path = "../data/AppIcons/"+icon_file;
}

void Game::run()
{
	Scene scene(360, 240, 1000);
	sf::RenderWindow window(sf::VideoMode(width, height), title);

	sf::Image icon;
	icon.loadFromFile(icon_path);
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	
	window.setFramerateLimit(60);

	sf::Event event;

	std::cout << ":Running Game:" << std::endl;
	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}
		window.clear(sf::Color(200, 200, 255));

		scene.render(&window);

		window.display();
	}
}
