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
	std::vector<StaticImage> expresions;
	std::string name;
	bool aligned_right = true;
};

struct Message
{
	std::string text;
	Face* face;
	Message* next;
};

class Conversation
{
	std::vector<Face> faces;
	std::vector<Message> messages;
	StaticImage text_box;
	vec2d position;
	int current_face = 0;
	int current_message = 0;
public:
	void load(std::string chat_data);
	void draw(Camera* camera, sf::RenderWindow* window);
};


#endif
