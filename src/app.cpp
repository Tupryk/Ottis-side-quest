#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "app.h"
#include "engineUI.h"
#include "Entities/block.h" // temporal //


void App::mod(char* arg_game)
{
	EngineUI engineUI(arg_game);

	if (engineUI.getInputs() == 1)
		run();
}

void App::run()
{
    Block block("../data/Games/Game0/Assets/Img/ottiface.png", 0, 0, 64, 64);

    sf::RenderWindow window(sf::VideoMode(1000, 1000), in_game);

	sf::Image icon;
    icon.loadFromFile("../data/AppIcons/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    window.setFramerateLimit(60);

    std::cout << ":Running Game:" << std::endl;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        window.clear(sf::Color(200, 200, 255));

        window.draw(block.draw());

        window.display();
    }
}
