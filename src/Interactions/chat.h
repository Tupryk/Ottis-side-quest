#ifndef CHAT
#define CHAT

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../Graphics/camera.h"
#include "../Graphics/sprites.h"
#include "../utils.h"


struct Face
{
	StaticImage normal;
	bool aligned_right = true;
};

struct Message
{
	std::string text;
	StaticImage* face;
	Message* next;
};

class Conversation
{
	std::vector<Face> faces;
	std::vector<Message> messages;
	StaticImage text_box;
	vec2d position;
public:
	void load(std::string chat_data);
	void draw(Camera* camera, sf::RenderWindow* window);
};


#endif
