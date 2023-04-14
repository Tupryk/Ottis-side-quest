#pragma once

#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "camera.h"
#include "../Physics/physics.h"


class Text
{
	sf::Font font;
	sf::Text text;
	int line_length = 0;

public:
	void init(std::string content, std::string font_file, int line_length = 0);
	void update(std::string content);
	void draw(float x, float y, sf::RenderWindow* window);
};

class DynamicText : StaticBody
{
	sf::Font font;
	sf::Text text;
	sf::Clock spelling_timer;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	std::string content;
	int line_length = 0;
	int letter_index = 0;
	// float speed;

public:
	void init(std::string content, std::string font_file, std::string sound_file, float speed, int line_length = 0);
	void update(std::string content, std::string sound_file = "");
	void reset();
	void draw(float x, float y, sf::RenderWindow* window);
};
