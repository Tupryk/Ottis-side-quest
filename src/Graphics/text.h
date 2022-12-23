#ifndef VISUAL_TEXT
#define VISUAL_TEXT


class Text
{
	sf::Font font;
	sf::Text text;
	sf::Text cursor;
	std::string text;
public:
	void init(std::string font_file);
	void update(std::string);
	void draw(float x, float y, sf::RenderWindow* window, float box_w = 0, float box_h = 0);
};

class DynamicText
{
	sf::Font font;
	sf::Text text;
	sf::Text cursor;
	sf::Clock SpellingTimer;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	std::string text;
public:
	void init(std::string font_file);
	void update(std::string);
	void draw(float x, float y, sf::RenderWindow* window, float box_w = 0, float box_h = 0);
};


#endif
