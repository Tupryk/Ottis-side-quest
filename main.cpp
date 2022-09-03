// g++ main.cpp -I//opt/homebrew/Cellar/sfml/2.5.1_1/include -o p -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system -std=c++11

#include <cmath>
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "ResourcePath.hpp"

#include "codestuff/code.cpp"

int main()
{
    sf::Image icon;
    icon.loadFromFile("Assets/img/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    srand (time_t(NULL));
    window.setFramerateLimit(60);

    World world;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        window.clear(sf::Color(200, 200, 255));

        world.update();

        window.display();
    }
    return 0;
}
