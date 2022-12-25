#include "text.h"


void Text::init(std::string font_file, std::string content, float x, float y, float w, float h)
{
    font.loadFromFile("../data/Games/Game0/Assets/Fonts/" + font_file);
	text.setFont(font);
	text.setString(content);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(48);
    text.scale(0.1f, 0.1f);

    position.x = x;
    position.y = y;
    size.x = w;
    size.y = h;
}

void Text::update(std::string content) {
	text.setString(content);
}

void Text::draw(float x, float y, sf::RenderWindow* window)
{
    text.setPosition(std::round(x), std::round(y));
    text.setFont(font);
    window->draw(text);
}

void DynamicText::init(std::string font_file, std::string content, std::string sound_file, float speed, float x, float y, float w, float h)
{
    font.loadFromFile("../data/Games/Game0/Assets/Fonts/" + font_file);
	text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(48);
    text.scale(0.1f, 0.1f);

    buffer.loadFromFile("../data/Games/Game0/Assets/Snd/" + sound_file);
	sound.setBuffer(buffer);

    this->content = content;
    position.x = x;
    position.y = y;
    size.x = w;
    size.y = h;
}

void DynamicText::update(std::string content, std::string sound_file) {
	if (sound_file != "")
		buffer.loadFromFile("../data/Games/Game0/Assets/Snd/" + sound_file);
	this->content = content;
}
void DynamicText::reset() {
	letter_index = 0;
}

void DynamicText::draw(float x, float y, sf::RenderWindow* window)
{
	text.setFont(font);
	sound.setBuffer(buffer);
	if (letter_index < content.length())
    {
		sf::Time lastUpdate = spelling_timer.getElapsedTime();
		if (lastUpdate.asMilliseconds() > 50)
		{
    		letter_index++;
    		sound.play();
    		text.setString(content.substr(0, letter_index));
    		spelling_timer.restart();
    	}
    } else {
    	text.setString(content);
    }
	text.setPosition(std::round(x), std::round(y));
    window->draw(text);
}
