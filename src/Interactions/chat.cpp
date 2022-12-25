#include "chat.h"


void Cursor::init(std::string font_file, int max_index)
{
	this->max_index = max_index;
	icon.init("pixeltupryk.ttf", ">");
}

void Cursor::reset() { index = 0; };

void Cursor::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !scroll_buffer) {
		scroll_buffer = true;
		index++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !scroll_buffer) {
		scroll_buffer = true;
		index--;
	}
	if (scroll_buffer &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		scroll_buffer = false;
	}
	if (index < 0) index = 0;
	if (index > max_index) index = max_index;
}

void Cursor::draw(Camera* camera, sf::RenderWindow* window)
{
	update();
	float set_x = camera->position.x - (camera->window_w*0.23);
	float set_y = camera->position.y - (camera->window_h*0.35) + (index*(camera->window_w*0.03));
	icon.draw(set_x, set_y, window);
}

void Conversation::load(std::string chat_data)
{
	std::vector<std::string> lines = getFileLines("../data/Games/Game0/Conversations/"+chat_data);
	for (int i = 0; i < lines.size(); i++)
	{
		std::vector<std::string> attributes = split(lines[i], ' ');
		if (attributes.size() >= 2)
		{
			if (attributes[0].compare("conversation_data") == 0) {
				attributes = split(lines[i], ' ');
				while (attributes.size() >= 1 && attributes[0] != "}")
				{
					if (attributes.size() >= 2)
					{
						if (attributes[0].compare("	message_box:") == 0)
							text_box.load(attributes[1], std::stoi(attributes[2]), std::stoi(attributes[3]));
					}
					i++;
					attributes = split(lines[i], ' ');
				}
			}
		}
	}
	cursor.init("pixeltupryk.ttf", 2);

	StaticImage new_exp;
	new_exp.load("ottiface.png", 64, 64);

	Face ne_face;
	ne_face.expresions.push_back(new_exp);
	ne_face.name.init("pixeltupryk.ttf", "Otti", 0, 0);
	ne_face.aligned_right = false;
	ne_face.sound = "nice_music.ogg";
	faces.push_back(ne_face);

	new_exp.load("gon_scene/gonFace.png", 64, 64);
	new_exp.flip();

	Face new_face;
	new_face.expresions.push_back(new_exp);
	new_face.name.init("pixeltupryk.ttf", "Gon", 0, 0);
	new_face.sound = "bruh.wav";
	faces.push_back(new_face);

	Message new_mess;
	new_mess.text = "jadioaiojdiojasiojdiojasiojdiojasio.";
	new_mess.face = 1;
	new_mess.expression = 0;
	new_mess.next = 1;
	messages.push_back(new_mess);

	Message new_new_mess;
	new_new_mess.text = "Helkidoajdid ajdjoaod gay.";
	new_new_mess.face = 0;
	new_new_mess.expression = 0;
	new_new_mess.next = -1;
	messages.push_back(new_new_mess);

	text.init("pixeltupryk.ttf", new_mess.text, faces[messages[current_message].face].sound, 0.2);
}

void Conversation::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !next_buffer) {
		next_buffer = true;
		cursor.reset();
		if (messages[current_message].next < 0) { *chatting = false; current_message = 0; }
		else current_message = messages[current_message].next;
		text.update(messages[current_message].text, faces[messages[current_message].face].sound);
		text.reset();
	} else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && next_buffer) {
		next_buffer = false;
	}
}

void Conversation::draw(Camera* camera, sf::RenderWindow* window)
{
	float set_x = camera->position.x;
	float set_y = camera->position.y - (camera->window_h*0.3);
	text_box.draw(set_x, set_y, window);

	// Faces
	if (faces[messages[current_message].face].aligned_right) set_x += (camera->window_h*0.6); else set_x -= (camera->window_h*0.6);
	faces[messages[current_message].face].expresions[messages[current_message].expression].draw(set_x, set_y, window);
	
	// Names
	set_x = camera->position.x - (camera->window_w*0.25);
	set_y = camera->position.y - (camera->window_h*0.4);
	faces[messages[current_message].face].name.draw(set_x, set_y, window);

	// Main text
	set_x = camera->position.x - (camera->window_w*0.2);
	set_y = camera->position.y - (camera->window_h*0.35);
	text.draw(set_x, set_y, window);

	// Cursor
	cursor.draw(camera, window);

	update();
}
