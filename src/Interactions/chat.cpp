#include "chat.h"


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
						if (attributes[0].compare("	x_pos:") == 0)
							position.x = std::stoi(attributes[1]);
						if (attributes[0].compare("	y_pos:") == 0)
							position.y = std::stoi(attributes[1]);
					}
					i++;
					attributes = split(lines[i], ' ');
				}
			}
		}
	}
	Face new_face;
	StaticImage new_exp;
	new_exp.load("gon_scene/gonFace.png", 64, 64);
	new_exp.flip();
	new_face.expresions.push_back(new_exp);
	new_face.name.init("pixeltupryk.ttf", "Gon", 0, 0);
	faces.push_back(new_face);

	Message new_mess;
	new_mess.text = "\"You are gay.\"";
	new_mess.character_name = (faces[0].name);
	new_mess.face = (faces[0].expresions[0]);
	new_mess.next = NULL;
	messages.push_back(new_mess);

	text.init("pixeltupryk.ttf", new_mess.text, "bruh.wav", 0.2);
}

void Conversation::draw(Camera* camera, sf::RenderWindow* window)
{
	float set_x = position.x+camera->position.x-(camera->window_w*0.2);
	float set_y = position.y+camera->position.y-(camera->window_h*0.35);
	text_box.draw(set_x, set_y, window);

	set_x = position.x+camera->position.x-(camera->window_w*0.2)+140;
	set_y = position.y+camera->position.y-(camera->window_h*0.35);
	messages[current_message].face.draw(set_x, set_y, window);
	
	messages[current_message].character_name.draw(camera, window);

	text.draw(camera, window);
}
