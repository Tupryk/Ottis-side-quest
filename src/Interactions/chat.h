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
	std::string sound = "";
	Text name;
	bool aligned_right = true;
};

struct Message
{
	std::string text;
	int face = 0;
	int expression = 0;
	int next = -1;
};

class Cursor
{
	Text icon;
	int index = 0;
	int max_index = 0;
	bool scroll_buffer = false;

	void update();

public:
	void init(std::string font_file, int max_index);
	void reset();
	void draw(Camera* camera, sf::RenderWindow* window);
};

class Conversation
{
	std::vector<Face> faces;
	std::vector<Message> messages;
	DynamicText text;
	StaticImage text_box;
	Cursor cursor;
	int current_message = 0;
	bool next_buffer = false;

	void update();

public:
	bool* chatting;
	void load(std::string chat_data);
	void draw(Camera* camera, sf::RenderWindow* window);
};


#endif
