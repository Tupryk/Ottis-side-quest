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
}

void Conversation::draw(Camera* camera, sf::RenderWindow* window)
{
	float set_x = position.x+camera->position.x-(camera->window_w*0.2);
	float set_y = position.y+camera->position.y-(camera->window_h*0.35);
	text_box.draw(set_x, set_y, window);
}
