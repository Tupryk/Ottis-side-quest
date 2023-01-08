#include "chat.h"


void Cursor::init(std::string font_file, int max_index)
{
	this->max_index = max_index;
	icon.init(">", "pixeltupryk.ttf");
}

void Cursor::reset(int max_index) { index = 0; this->max_index = max_index; };

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
	initial_messages = {0};
	current_messages = initial_messages;

	cursor.init("pixeltupryk.ttf", current_messages.size()-1);

	StaticImage new_exp;
	new_exp.load("ottiface.png", 64, 64);

	Face ne_face;
	ne_face.expresions.push_back(new_exp);
	ne_face.name.init("Otti", "pixeltupryk.ttf");
	ne_face.aligned_right = false;
	ne_face.sound = "nice_music.ogg";
	faces.push_back(ne_face);

	new_exp.load("gon_scene/gonFace.png", 64, 64);
	new_exp.flip();

	Face new_face;
	new_face.expresions.push_back(new_exp);
	new_face.name.init("Gon", "pixeltupryk.ttf");
	new_face.sound = "bruh.wav";
	faces.push_back(new_face);

	Message new_mess;
	new_mess.text = "jadioaiojdiojasiojdiojasiojdiojasio.";
	new_mess.face = 1;
	new_mess.expression = 0;
	new_mess.options = {1, 0};
	messages.push_back(new_mess);

	Message new_new_mess;
	new_new_mess.text = "Helkidoajdid ajdjoaod gay.";
	new_new_mess.face = 0;
	new_new_mess.expression = 0;
	new_mess.options = {};
	messages.push_back(new_new_mess);

	text.init(new_mess.text, "pixeltupryk.ttf", faces[messages[current_messages[0]].face].sound, 0.2);
	option_disp.init("", "pixeltupryk.ttf");

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
			if (attributes[0].compare("message") == 0) {
				Message new_mess;
				messages.push_back(new_mess);
				attributes = split(lines[i], ' ');
				while (attributes.size() >= 1 && attributes[0] != "}")
				{
					if (attributes.size() >= 2)
					{
						if (attributes[0].compare("	text:") == 0) {
							//messages[messages.size()-1].text = lines;
						}
						if (attributes[0].compare("	next:") == 0) {
							for (int j = 0; j < attributes.size(); j++){
								//messages[messages.size()-1].options.push_back(attributes[i]);
							}
						}
					}
					i++;
					attributes = split(lines[i], ' ');
				}
				messages[messages.size()-1].face = 1;
				messages[messages.size()-1].expression = 0;
			}
			if (attributes[0].compare("using_face") == 0) {
				Face new_face;
				std::string name;
				std::string font;
				attributes = split(lines[i], ' ');
				while (attributes.size() >= 1 && attributes[0] != "}")
				{
					if (attributes.size() >= 2)
					{
						if (attributes[0].compare("	sound:") == 0)
							new_face.sound = attributes[1];
						else if (attributes[0].compare("	font:") == 0)
							font = attributes[1];
						else if (attributes[0].compare("	name:") == 0)
							name = attributes[1];
						else if (attributes[0].compare("	aligned:") == 0) {
							if (attributes[1].compare("left"))
								ne_face.aligned_right = false;
						}
					}
					i++;
					attributes = split(lines[i], ' ');
				}
				new_face.expresions.push_back(new_exp);
				new_face.name.init(name, font);
				faces.push_back(new_face);
			}
		}
	}
}

void Conversation::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !next_buffer) {
		if (messages[current_messages[cursor.index]].options.empty()) {
			*chatting = false;
			current_messages = initial_messages;
		} else {
			current_messages = messages[current_messages[cursor.index]].options;
		}
		text.update(messages[current_messages[0]].text, faces[messages[current_messages[0]].face].sound);
		text.reset();
		cursor.reset(current_messages.size()-1);
		next_buffer = true;
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
	if (faces[messages[current_messages[cursor.index]].face].aligned_right)
		set_x += (camera->window_h*0.6); else set_x -= (camera->window_h*0.6);
	faces[messages[current_messages[cursor.index]].face].expresions[messages[current_messages[cursor.index]].expression].draw(set_x, set_y, window);
	
	// Names
	set_x = camera->position.x - (camera->window_w*0.25);
	set_y = camera->position.y - (camera->window_h*0.4);
	faces[messages[current_messages[cursor.index]].face].name.draw(set_x, set_y, window);

	// Main text
	set_x = camera->position.x - (camera->window_w*0.2);
	set_y = camera->position.y - (camera->window_h*0.35);

	if (current_messages.size() > 1) {
		for (int i = 0; i < current_messages.size(); i++) {
			option_disp.update(messages[current_messages[i]].text);
			option_disp.draw(set_x, set_y, window);
			set_y += camera->window_w*0.03;
		}
		// Cursor
		cursor.draw(camera, window);
	} else {
		text.draw(set_x, set_y, window);
	}

	update();
}
