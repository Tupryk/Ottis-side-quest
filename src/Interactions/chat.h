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
	std::vector<int> options;
};

class Cursor
{
	Text icon;
	int max_index = 0;
	bool scroll_buffer = false;

	void update();

public:
	int index = 0;

	void init(std::string font_file, int max_index);
	void reset(int max_index = 0);
	void draw(Camera* camera, sf::RenderWindow* window);
};

class Conversation
{
	std::vector<Face> faces;
	std::vector<Message> messages;
	DynamicText text;
	Text option_disp;
	StaticImage text_box;
	Cursor cursor;
	std::vector<int> initial_messages;
	std::vector<int> current_messages;
	bool next_buffer = false;

	void update();

public:
	bool* chatting;
	void load(std::string chat_data);
	void draw(Camera* camera, sf::RenderWindow* window);
};


#endif
