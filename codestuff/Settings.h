#ifndef SETTINGS
#define SETTINGS

const int ScreenWidth = 360;
const int ScreenHeight = 240;
//sf::Style::Fullscreen
sf::RenderWindow window(sf::VideoMode(1280, 720), "Otti's Side Quest (Alpha)");
sf::View camera(sf::FloatRect(-ScreenWidth/2, -ScreenHeight/2, ScreenWidth, ScreenHeight));

#endif
