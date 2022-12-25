#ifndef VISUAL_TEXT
#define VISUAL_TEXT

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "camera.h"
#include "../Physics/physics.h"


class Text : StaticBody
{
	sf::Font font;
	sf::Text text;

public:
	void init(std::string font_file, std::string content, float x = 0, float y = 0, float w = 0, float h = 0);
	void update(std::string content);
	void draw(Camera* camera, sf::RenderWindow* window);
};

class DynamicText : StaticBody
{
	sf::Font font;
	sf::Text text;
	sf::Clock spelling_timer;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	std::string content;
	float speed;
	int letter_index = 0;

public:
	void init(std::string font_file, std::string content, std::string sound_file, float speed, float x = 0, float y = 0, float w = 0, float h = 0);
	void update(std::string content);
	void reset();
	void draw(Camera* camera, sf::RenderWindow* window);
};


#endif
