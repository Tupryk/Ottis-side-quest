#ifndef CHAT
#define CHAT

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../Graphics/camera.h"
#include "../Graphics/sprites.h"
#include "../Graphics/text.h"
#include "../utils.h"


struct Face
{
	std::vector<StaticImage> expresions;
	Text name;
	bool aligned_right = true;
};

struct Message
{
	std::string text;
	Text character_name;
	StaticImage face;
	Message* next;
};

class Conversation
{
	std::vector<Face> faces;
	std::vector<Message> messages;
	DynamicText text;
	StaticImage text_box;
	vec2d position;
	int current_message = 0;

public:
	void load(std::string chat_data);
	void draw(Camera* camera, sf::RenderWindow* window);
};


#endif
