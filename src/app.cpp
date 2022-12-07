#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "app.h"
#include "engineUI.h"


void App::mod(char* arg_game)
{
	EngineUI engineUI(arg_game);

	if (engineUI.getInputs() == 1)
		run();
}

void App::run()
{
	sf::Image icon;
    icon.loadFromFile(resourcePath() + "../data/AppIcons/icon.png");
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

        window.display();
    }
    return 0;
}
